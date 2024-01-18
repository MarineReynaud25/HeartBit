## Description

This project enables communication between two ESP32 Mini boards using the ESP-NOW protocol. Each board is equipped with a button, an LED, and a vibration motor. When a button on ESP32 A is pressed, it triggers the LED and vibration motor on ESP32 B, and vice versa.

## Components
- 2 x ESP32 C3 Mini
- 2 x Push Buttons
- 2 x LEDs
- 2 x Vibration Motors
- Connection Wires
- Resistors (for LEDs)
- Breadboard or Perfboard

## Hardware Setup
1. Connect the 2 ESP32s to a breadboard.
2. For each board, connect the push button, LED, and motor to the GPIO pins of the ESP32, which will be referred to as INTERRUPT_PIN, LedPin, and MOTOR in the code.

## Installation
1. Install the Arduino IDE and the necessary packages for ESP32.
2. Clone this repository to your local machine.
3. Open the code file in the Arduino IDE.
4. Upload the code to both ESP32 boards.

## Software Configuration
- Ensure the MAC addresses in the code (`broadcastAddress`) are correctly set for each ESP32.
- The code must be uploaded to both ESP32s with their respective MAC addresses.

## Usage
After powering up both ESP32 boards, press the button on one of the boards. This should activate the LED and vibration motor on the other board.

## Code
The provided code establishes ESP-NOW communication between two ESP32s. It handles sending and receiving messages, as well as controlling external devices (LED and vibration motor) in response to button inputs.

### Main Functions
- `OnDataSent`: Callback called after sending a message.
- `OnDataRecv`: Callback called upon receiving a message.
- `isr_callback`: Function called during interruption by the push button.
