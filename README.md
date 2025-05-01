# Temperature-Based Fan Speed Control Using DHT Sensor

## Overview
This project dynamically adjusts the speed of a **fan** based on temperature readings from a **DHT11/DHT22** sensor. The system uses **PWM control** to regulate fan speed, making it ideal for environmental automation.

## Components Used
- **Arduino Uno**
- **DHT11 or DHT22 Temperature & Humidity Sensor**
- **Fan (PWM controlled)**
- **Resistors & Wires**
- **Breadboard**

## Features
- **Temperature Sensing:** Reads temperature values from the DHT sensor.
- **Automatic Speed Adjustment:** Maps temperature readings to appropriate **PWM fan speeds**.
- **Serial Output:** Displays real-time temperature and fan speed data.
- **Failsafe Handling:** Detects sensor reading errors and prevents invalid operations.

## Wiring Diagram
| Component        | Pin Connection |
|-----------------|---------------|
| **DHT Sensor Data** | D3 |
| **Fan PWM Control** | D9 |

## Code Explanation
- **Setup Function (`setup()`)**:
  - Initializes the DHT sensor.
  - Sets the **fan control pin** as an output.
  - Begins **serial communication** for debugging.

- **Loop Function (`loop()`)**:
  - Reads **temperature** from the sensor.
  - Checks for **sensor errors**.
  - Maps temperature values to **fan speed (0-255 PWM)**.
  - Outputs **sensor readings & fan speed** to the Serial Monitor.

- **Temperature to Speed Mapping (`map()`)**:
  - Converts **temperature range (28°C to 36°C)** into **PWM values (0-255)**.
  - Prevents extreme values using **`constrain()`**.

## Installation & Usage
1. **Connect Components** according to the wiring diagram.
2. **Upload the Arduino Code** using the Arduino IDE.
3. **Monitor Serial Output** to track **temperature** and **fan speed**.
4. **Observe Fan Behavior**—speed will increase as temperature rises.

## Future Improvements
- Add **humidity-based control** for additional environmental regulation.
- Implement **LCD or OLED display** for direct monitoring.
- Enhance **EEPROM storage** to retain last fan speed settings.

## Author
- [Pritiii29]
