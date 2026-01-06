/*
  Water Dispenser Powered by Wind Generator (baseline sketch)

  Reads an IR sensor and switches a relay to run a small pump for a fixed time.

  NOTE:
  - Arduino Uno generally needs stable 5V power. If your wind generator output is unstable,
    use rectification + regulation + buffering (battery/supercap) before powering the Arduino/relay.
*/

#include <Arduino.h>

// Pin configuration
const uint8_t IR_PIN    = 2;   // IR sensor OUT
const uint8_t RELAY_PIN = 8;   // Relay IN

// Logic configuration
// Many IR modules output LOW when an object is detected.
const uint8_t IR_ACTIVE_STATE = LOW;

// Many relay modules are active LOW (IN=LOW turns relay ON).
const uint8_t RELAY_ACTIVE_STATE = LOW;

// Timing configuration (milliseconds)
const unsigned long DISPENSE_MS = 1500;
const unsigned long DEBOUNCE_MS = 80;
const unsigned long LOCKOUT_MS  = 1500;

bool lastStableDetected = false;
bool lastRead = false;
unsigned long lastEdgeMs = 0;
unsigned long lastCycleMs = 0;

void setRelay(bool on) {
  digitalWrite(RELAY_PIN, on ? RELAY_ACTIVE_STATE : (RELAY_ACTIVE_STATE == LOW ? HIGH : LOW));
}

bool detectedRaw() {
  return digitalRead(IR_PIN) == IR_ACTIVE_STATE;
}

void setup() {
  pinMode(IR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  setRelay(false);

  Serial.begin(9600);
  Serial.println("Wind Dispenser baseline sketch started.");
}

void loop() {
  const unsigned long now = millis();
  const bool current = detectedRaw();

  // Debounce
  if (current != lastRead) {
    lastRead = current;
    lastEdgeMs = now;
  }

  if (now - lastEdgeMs >= DEBOUNCE_MS) {
    if (lastStableDetected != lastRead) {
      lastStableDetected = lastRead;

      // Trigger on rising edge (no object -> object)
      if (lastStableDetected) {
        if (now - lastCycleMs >= LOCKOUT_MS) {
          lastCycleMs = now;

          Serial.println("Detected -> dispensing...");
          setRelay(true);
          delay(DISPENSE_MS);
          setRelay(false);
          Serial.println("Done.");
        } else {
          Serial.println("Detected but in lockout window.");
        }
      }
    }
  }
}
