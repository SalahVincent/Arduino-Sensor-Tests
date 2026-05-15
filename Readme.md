# Arduino-Sensor-Tests

A lightweight, non-blocking Arduino-based embedded system designed to monitor environmental data, handle manual user inputs, and process external serial commands in real-time. 

This version replaces standard delays with an efficient, timer-based execution loop to ensure high responsiveness.

## Preview
![preview1](./assets/images/node-red.png)
![preview2](./assets/images/ui.png)
![preview3](./assets/images/code-preview.png)


## Features
* **Non-Blocking Timing Engine:** Uses `millis()` for sensor sampling and LCD refreshes, eliminating processor lag and allowing continuous operation.
* **Real-time Serial Command Processing:** Listens continuously for external serial inputs to instantly control hardware peripherals (e.g., toggling the status LED).
* **Memory-Optimized Data Streaming:** Transmits sensor readings over Serial without the overhead of heavy `String` objects, preventing memory fragmentation.
* **Flicker-Free LCD Interface:** Overwrites explicit cursor positions on a 16x2 I2C LCD to maintain a clean display without screen flickering.

## Hardware Requirements
* **Microcontroller:** Arduino (Uno, Nano, or compatible)
* **Display:** 16x2 LCD with I2C Expander (MCP23008)
* **Sensors & Components:**
    * **Temperature Sensor:** Connected to A2
    * **Light Sensor (LDR):** Connected to A3
    * **Potentiometer:** Connected to A1
    * **Buzzer:** Connected to Digital Pin 2
    * **Push Button:** Connected to Digital Pin 8
    * **LED:** Connected to Digital Pin 13

## Prerequisites
You will need the following libraries installed in your Arduino IDE:
* `hd44780` by Bill Perry (Available via the Library Manager)
* `Wire.h` (Standard library)

## Installation & Usage
1. **Clone the repository:**
   ```bash
   git clone [https://github.com/SalahVincent/Arduino-Sensor-Tests.git](https://github.com/SalahVincent/Arduino-Sensor-Tests.git)
   
```markdown
# Arduino-Sensor-Tests

A lightweight, non-blocking Arduino-based embedded system designed to monitor environmental data, handle manual user inputs, and process external serial commands in real-time. 

This version replaces standard delays with an efficient, timer-based execution loop to ensure high responsiveness.

## Features
* **Non-Blocking Timing Engine:** Uses `millis()` for sensor sampling and LCD refreshes, eliminating processor lag and allowing continuous operation.
* **Real-time Serial Command Processing:** Listens continuously for external serial inputs to instantly control hardware peripherals (e.g., toggling the status LED).
* **Memory-Optimized Data Streaming:** Transmits sensor readings over Serial without the overhead of heavy `String` objects, preventing memory fragmentation.
* **Flicker-Free LCD Interface:** Overwrites explicit cursor positions on a 16x2 I2C LCD to maintain a clean display without screen flickering.

## Hardware Requirements
* **Microcontroller:** Arduino (Uno, Nano, or compatible)
* **Display:** 16x2 LCD with I2C Expander (MCP23008)
* **Sensors & Components:**
    * **Temperature Sensor:** Connected to A2
    * **Light Sensor (LDR):** Connected to A3
    * **Potentiometer:** Connected to A1
    * **Buzzer:** Connected to Digital Pin 2
    * **Push Button:** Connected to Digital Pin 8
    * **LED:** Connected to Digital Pin 13

## Prerequisites
You will need the following libraries installed in your Arduino IDE:
* `hd44780` by Bill Perry (Available via the Library Manager)
* `Wire.h` (Standard library)

## Installation & Usage
1. **Clone the repository:**
   ```bash
   git clone [https://github.com/SalahVincent/Arduino-Sensor-Tests.git](https://github.com/SalahVincent/Arduino-Sensor-Tests.git)