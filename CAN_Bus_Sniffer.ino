#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;
MCP2515 mcp2515(10);   // PIN 10

void setup() {
  Serial.begin(115200);
  while (!Serial);

  SPI.begin();

  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);

  //Safe sniffer (listen only)
  mcp2515.setListenOnlyMode();

  Serial.println("CAN SNIFFER READY (LISTEN-ONLY)");
}

void loop() {
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {

    Serial.print("ID: 0x");
    Serial.print(canMsg.can_id, HEX);

    Serial.print(" DLC: ");
    Serial.print(canMsg.can_dlc);

    Serial.print(" Data: ");
    for (uint8_t i = 0; i < canMsg.can_dlc; i++) {
      if (canMsg.data[i] < 0x10) Serial.print("0");
      Serial.print(canMsg.data[i], HEX);
      Serial.print(" ");
    }

    Serial.println();
  }
}
