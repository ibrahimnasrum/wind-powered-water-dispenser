# Arduino Sketch

## Files
- `wind_dispenser.ino` — baseline dispenser controller

## Default behavior
- When IR sensor detects an object, the pump turns ON for `DISPENSE_MS`

## Default pins
- IR sensor OUT -> D2
- Relay IN      -> D8

## If it doesn’t work
- Invert sensor logic by changing `IR_ACTIVE_STATE`
- Invert relay logic by changing `RELAY_ACTIVE_STATE`
