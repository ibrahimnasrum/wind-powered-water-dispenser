# Wiring Notes (Suggested)

Because the original wiring diagram/code was lost after an OS reset, this is a safe baseline.

## IR sensor (typical module)
- VCC -> 5V (Arduino)
- GND -> GND
- OUT -> D2 (default)

Many IR sensors output LOW when object detected. The code supports changing this.

## Relay module (1-channel 5V)
- VCC -> 5V (Arduino)
- GND -> GND
- IN  -> D8 (default)

Many relay modules are active LOW. The code supports changing this.

## Pump power
Power the pump using your wind generator output (recommended: rectified + regulated), or a separate supply.

If separate supply: share GND with Arduino when controlling a relay module.

WARNING:
- An Arduino Uno needs stable 5V; a wind generator output can be noisy/variable.
- For reliable control: rectify + regulate + buffer (battery/supercap).
