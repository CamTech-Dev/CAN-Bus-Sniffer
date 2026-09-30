# CAN Bus Sniffer

A passive, listen-only CAN bus monitoring project using an MCP2515 CAN controller.

The system reads CAN frames from a 500 kbps CAN network without transmitting onto the bus and outputs the CAN identifier, data length code, and payload bytes through the serial monitor.

## Features

- Listen-only mode for passive monitoring
- MCP2515 CAN controller
- SPI communication
- 500 kbps CAN bitrate
- Listen-only mode for passive monitoring
- Displays CAN ID, DLC, and payload data
- Serial output at 115200 baud

## Hardware

- Arduino-compatible microcontroller
- MCP2515 CAN controller module
- CAN transceiver
- USB cable
- CAN bus connection

## Configuration

- CAN bitrate: 500 kbps
- MCP2515 oscillator: 8 MHz
- SPI chip select: Pin 10
- Serial baud rate: 115200
- Operating mode: Listen-only

## How to Run

1. Open `CAN_Bus_Sniffer.ino` in the Arduino IDE.
2. Install the MCP2515 library.
3. Connect the MCP2515 module to the microcontroller over SPI.
4. Connect the CAN transceiver/module to the vehicle's OBD-II CAN lines.
5. Connect the microcontroller to the computer over USB.
6. Upload the sketch.
7. Open the Serial Monitor at 115200 baud.
8. Turn the vehicle ignition on so the CAN network is active.
9. Observe CAN frames in real time.

The MCP2515 is configured in listen-only mode, so the project passively monitors CAN traffic without transmitting frames onto the bus.

> Note: This project is configured for a 500 kbps CAN bus and an 8 MHz MCP2515 oscillator. The vehicle network must use the same CAN bitrate for frames to be decoded correctly.

## How It Works

The microcontroller communicates with the MCP2515 over SPI. The MCP2515 is configured in listen-only mode, allowing the device to passively observe CAN traffic without transmitting frames or interfering with normal bus communication.

Received frames are displayed in the following format:

```text
ID: 0x123 DLC: 8 Data: 01 02 03 04 05 06 07 08

