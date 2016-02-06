#include <Wire.h>
#include <avr/pgmspace.h>
#include "I2C_eeprom.h"
#include "ConfigBlock.h"
#include "MenuBlock.h"

#define MEM_CHIP_ADDR 0x50


#define PREERENCES_SIZE           2

bool wasRun = false;

I2C_eeprom ee(0x50);
byte ledState = LOW;

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  if (!wasRun) {
    uint16_t offset = MEM_DATA_ADDR;
    offset = writeMenuUa(offset, &ee, true);
    offset = writeMenuEn(offset, &ee, true);
    offset = writePreferences(offset, &ee);

    wasRun = true;
    Serial.println("Data has been loaded into EEPROM");
  }

  digitalWrite(13, ledState);
  if (ledState == LOW) {
    ledState = HIGH;
  } else {
    ledState = LOW;
  }
  delay(200);
}

// --------------------------------------------------------------

//void readProgmem() {
//  byte data = 0;
//  for (int i = 0; i < MENU_ROWS; i++) {
//    for (int j = 0; j < MENU_LINE_LENGTH; j++) {
//      data = pgm_read_byte(menuUaBlock + i * MENU_LINE_LENGTH + j);
//      Serial.print(data, HEX);
//      Serial.print(" ");
//    }
//    Serial.println();
//  }
//}

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

//
//void readMenu(int startAddr) {
//  for (int i = 0; i < MENU_ROWS; i++) {
//    for (int j = 0; j < MENU_LINE_LENGTH; j++) {
//      Serial.print(ee.readByte(startAddr + i * MENU_LINE_LENGTH + j), HEX);
//      Serial.print(" ");
//    }
//    Serial.println();
//  }
//}

