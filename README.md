# Water Dispenser Powered by Wind Generator

A mini renewable-energy lab project that uses a **wind turbine (DC motors used as generators)** to produce electricity for a **water dispenser / pump system**. The project studies how wind speed affects generated voltage and pump operation.

📄 Full report: `docs/PROJECT_LAB_1_Wind_Turbine.pdf`

---

## Overview

Renewable energy is energy from a source that is not depleted when used (e.g., wind or solar). In this project we use wind to generate electricity for a water dispenser.

---

## Objectives

- **Main objective:** Make a water dispenser using only the wind turbine as the main voltage source.
- **Secondary objective:** Examine the relationship between **wind turbine**, **voltage**, and **pump**.

---

## How it works (theory)

### Wind turbine
Wind turns the turbine blades, converting wind kinetic energy into rotary motion. The turbine drives a generator (a DC motor used in reverse) to create electrical current.

### Centrifugal water pump
A centrifugal pump moves fluid by transferring rotational energy from an impeller to the fluid, increasing fluid velocity and pressure toward the outlet.

---

## Equipment & materials

- 8 × DC Motor
- Aluminium tin
- Digital multimeter
- Wires (red/black)
- Blower (wind source)
- Arduino Uno R3
- Infrared sensor
- Boxes
- Toothpaste cap + water bottle cap
- Sticks
- Wood block
- Water pump (3V–5V)
- Tube / hose
- Relay 5V

Add photos/screenshots in `docs/images/`, then link here:

![Equipment & Material](docs/images/equipment_material.png)

---

## Procedure

1. Sketch the model
2. Build the wind turbine
3. Construct the circuit for the water dispenser
4. Test turbine polarity and circuit (simple calculation)
5. Assemble all components (wind turbine + circuit)
6. Run the machine

---

## Build photos (optional)

![Breadboard circuit](docs/images/build_circuit_breadboard.png)
![Polarity test](docs/images/test_polarity_multimeter.png)
![Assembled setup](docs/images/assembled_setup.png)

---

## Relationship: wind speed → voltage → pump

- **V_turbine = k · v_wind**
- **V_pump = V_turbine**
- **P_input = V_pump · I_pump**
- **η = (Wind Turbine Input Power) / (Useful Power Output)**

---

## Problems & solutions

![Problems & solution](docs/images/problems_solutions.png)

Common issues:
- Hard to obtain stable voltage due to blower angle changes
- Turbine blades break under high wind
- Relay issues due to unstable voltage
- Loud blower affects nearby residents
- Electrical output fluctuates with wind speed

Suggested improvements:
- Repeat tests to find best blower angle for maximum speed/voltage
- Use stronger blade materials (wood/aluminium)
- Confirm relay minimum voltage requirements
- Choose an appropriate lab/location
- Add power electronics (converter/regulator) to stabilize output (DC regulation)

---

## Arduino code

The original code was lost after an OS reset, so this repo includes a **fresh baseline sketch**:

- `src/arduino/wind_dispenser.ino`

It reads an IR sensor and switches a relay to run the pump for a configurable time.

> ⚠️ Arduino Uno typically needs a stable 5V supply. If your turbine output is unstable, add a rectifier + regulator (or buffer with a battery/supercap).

---

## Group Members

1. Ibrahim bin Nasrum (2116467)
2. Muhammad Hafidzuddin Hanif (2123651)
3. Shareen Arawie bin Hisham (2116943)
4. Muhamad Azri bin Abdul Aziz (2113537)


---
