# CAN Bus Sniffer

A passive CAN bus monitoring project using an MCP2515 CAN controller.

The system reads CAN frames from a 500 kbps CAN network and outputs the CAN identifier, data length code, and payload bytes through the serial monitor.

## Features

- MCP2515 CAN controller
- SPI communication
- 500 kbps CAN bitrate
- Listen-only mode for passive monitoring
- Displays CAN ID, DLC, and payload data
- Serial output at 115200 baud

## Hardware

- Microcontroller board
- MCP2515 CAN controller module
- CAN transceiver
- CAN bus connection

## How It Works

The microcontroller communicates with the MCP2515 over SPI. The MCP2515 is configured in listen-only mode so that the device can observe CAN traffic without transmitting onto the bus.

Received frames are displayed in the following format:

```text
ID: 0x123 DLC: 8 Data: 01 02 03 04 05 06 07 08
