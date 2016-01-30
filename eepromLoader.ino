#include <Wire.h>
#include <avr/pgmspace.h>
#include "I2C_eeprom.h"
#include "ConfigBlock.h"
#include "menuUaBlock.h"

#define MEM_CHIP_ADDR 0x50

bool wasRun = false;

I2C_eeprom ee(0x50);

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);             // Leonardo: wait for serial monitor
}

void loop() {
  if (!wasRun) {
    unsigned int offset = MEM_DATA_ADDR;
    writeMenuUa(offset);
    readMenuUa(offset);
    //    readProgmem();
    wasRun = true;
  }
}

// --------------------------------------------------------------

void readProgmem() {
  byte data = 0;
  for (int i = 0; i < MENU_UA_ROWS; i++) {
    for (int j = 0; j < MENU_UA_LINE_LENGTH; j++) {
      data = pgm_read_byte(menuUaBlock + i * MENU_UA_LINE_LENGTH + j);
      Serial.print(data, HEX);
      Serial.print(" ");
    }
    Serial.println();
  }
}

unsigned int readInt(unsigned int address) {
  byte lowByte = ee.readByte(address);
  byte highByte = ee.readByte(address + 1);

  return ((lowByte << 0) & 0xFF) + ((highByte << 8) & 0xFF00);
}

void writeInt(unsigned int address, unsigned int value) {
  byte lowByte = ((value >> 0) & 0xFF);
  byte highByte = ((value >> 8) & 0xFF);

  ee.writeByte(address, lowByte);
  ee.writeByte(address + 1, highByte);
}

// -----------------------------------------------------------------

void writeMenuUa(unsigned int startAddr) {
  Serial.println("Start read data");
  unsigned int testInt = readInt(MENU_UA_BLOCK_ADDR);
  if (startAddr != testInt) {
    writeInt(MENU_UA_BLOCK_ADDR, startAddr);
  }

  int menuUaBlockSize = MENU_UA_LINE_LENGTH * MENU_UA_ROWS;
  char data = 0;
  char testdata = 0;
  for (int i = 0; i < MENU_UA_ROWS; i++) {
    for (int j = 0; j < MENU_UA_LINE_LENGTH; j++) {
      data = (char) pgm_read_byte(menuUaBlock + i * MENU_UA_LINE_LENGTH + j);
      testdata = (char) ee.readByte(startAddr + i * MENU_UA_LINE_LENGTH + j);
      if (testdata != data) {
        ee.writeByte(startAddr + i * MENU_UA_LINE_LENGTH + j, data);
      }
    }
  }

  Serial.println("Finished read data " + String(menuUaBlockSize) + " bytes");
}

void readMenuUa(int startAddr) {
  for (int i = 0; i < MENU_UA_ROWS; i++) {
    for (int j = 0; j < MENU_UA_LINE_LENGTH; j++) {
      Serial.print(ee.readByte(startAddr + i * MENU_UA_LINE_LENGTH + j), HEX);
      Serial.print(" ");
    }
    Serial.println();
  }

}

