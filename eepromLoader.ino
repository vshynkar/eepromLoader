#include <Wire.h>
#include <avr/pgmspace.h>
#include "I2C_eeprom.h"
#include "ConfigBlock.h"
#include "menuUaBlock.h"
#include "menuEngBlock.h"

#define MEM_CHIP_ADDR 0x50

#define MENU_LINE_LENGTH          14
#define MENU_ROWS                 20

bool wasRun = false;

I2C_eeprom ee(0x50);

void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);             // Leonardo: wait for serial monitor
}

void loop() {
  if (!wasRun) {
    uint16_t offset = MEM_DATA_ADDR;
    writeMenuUa(offset);
    readMenu(offset);
    //    readProgmem();

    offset = offset + (MENU_LINE_LENGTH * MENU_ROWS);
    writeMenuEn(offset);
    readMenu(offset);
    wasRun = true;
  }
}

// --------------------------------------------------------------

void readProgmem() {
  byte data = 0;
  for (int i = 0; i < MENU_ROWS; i++) {
    for (int j = 0; j < MENU_LINE_LENGTH; j++) {
      data = pgm_read_byte(menuUaBlock + i * MENU_LINE_LENGTH + j);
      Serial.print(data, HEX);
      Serial.print(" ");
    }
    Serial.println();
  }
}

unsigned int readInt(uint16_t address) {
  byte lowByte = ee.readByte(address);
  byte highByte = ee.readByte(address + 1);

  return ((lowByte << 0) & 0xFF) + ((highByte << 8) & 0xFF00);
}

void writeInt(uint16_t address, uint16_t value) {
  byte lowByte = ((value >> 0) & 0xFF);
  byte highByte = ((value >> 8) & 0xFF);

  ee.writeByte(address, lowByte);
  ee.writeByte(address + 1, highByte);
}

// -----------------------------------------------------------------

void writeMenuUa(uint16_t startAddr) {
  Serial.println("Start UA read data");
  uint16_t testInt = readInt(MENU_UA_BLOCK_ADDR);
  if (startAddr != testInt) {
    writeInt(MENU_UA_BLOCK_ADDR, startAddr);
  }

  int menuUaBlockSize = MENU_LINE_LENGTH * MENU_ROWS;
  char data = 0;
  char testdata = 0;
  for (int i = 0; i < MENU_ROWS; i++) {
    for (int j = 0; j < MENU_LINE_LENGTH; j++) {
      data = (char) pgm_read_byte(menuUaBlock + i * MENU_LINE_LENGTH + j);
      testdata = (char) ee.readByte(startAddr + i * MENU_LINE_LENGTH + j);
      if (testdata != data) {
        ee.writeByte(startAddr + i * MENU_LINE_LENGTH + j, data);
      }
    }
  }

  Serial.println("Finished read data " + String(menuUaBlockSize) + " bytes");
}


void writeMenuEn(uint16_t startAddr) {
  Serial.println("Start EN read data");
  uint16_t testInt = readInt(MENU_EN_BLOCK_ADDR);
  if (startAddr != testInt) {
    writeInt(MENU_EN_BLOCK_ADDR, startAddr);
  }

  int menuEnBlockSize = MENU_LINE_LENGTH * MENU_ROWS;
  char data = 0;
  char testdata = 0;
  for (int i = 0; i < MENU_ROWS; i++) {
    for (int j = 0; j < MENU_LINE_LENGTH; j++) {
      data = (char) pgm_read_byte(menuEnBlock + i * MENU_LINE_LENGTH + j);
      testdata = (char) ee.readByte(startAddr + i * MENU_LINE_LENGTH + j);
      if (testdata != data) {
        ee.writeByte(startAddr + i * MENU_LINE_LENGTH + j, data);
      }
    }
  }

  Serial.println("Finished read data " + String(menuEnBlockSize) + " bytes");
}

void readMenu(int startAddr) {
  for (int i = 0; i < MENU_ROWS; i++) {
    for (int j = 0; j < MENU_LINE_LENGTH; j++) {
      Serial.print(ee.readByte(startAddr + i * MENU_LINE_LENGTH + j), HEX);
      Serial.print(" ");
    }
    Serial.println();
  }
}

