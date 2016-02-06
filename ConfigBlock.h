#ifndef _CONFIG_BLOCK_H
#define _CONFIG_BLOCK_H

#ifdef __AVR__
#include <avr/io.h>
#include <avr/pgmspace.h>
#elif defined(ESP8266)
#include <pgmspace.h>
#else
#define PROGMEM
#endif

#include "I2C_eeprom.h"

#define BOUND_RATE_19200    19200
#define BOUND_RATE_28800    28800
#define BOUND_RATE_31250    31250
#define BOUND_RATE_38400    38400
#define BOUND_RATE_57600    57600
#define BOUND_RATE_115200   115200

#define MEM_DATA_ADDR           0x14

// status block
#define MENU_EN_BLOCK_ADDR      0x00
#define MENU_UA_BLOCK_ADDR      0x02
#define CONFIG_BLOCK_ADDR       0x04
#define MEM_STRUCTURE_VERSION   0x06
#define RESERVED_2_ADDR         0x08
#define RESERVED_3_ADDR         0x0A
#define RESERVED_4_ADDR         0x0C
#define RESERVED_5_ADDR         0x0E
#define RESERVED_6_ADDR         0x10
#define RESERVED_7_ADDR         0x12

// preferences block
#define LANGUAGE_ADDR_OFFSET    0x00
#define SERIAL_SPEED_OFFSET     0x02


uint16_t writePreferences(uint16_t configStartAddr, I2C_eeprom* ee) {
  ee->writeInt(CONFIG_BLOCK_ADDR, configStartAddr);

  uint16_t currentLangNewAddr = ee->readInt(MENU_UA_BLOCK_ADDR);
  ee->writeInt(configStartAddr + LANGUAGE_ADDR_OFFSET, currentLangNewAddr);

  ee->writeInt(configStartAddr + SERIAL_SPEED_OFFSET, int(BOUND_RATE_57600 / 10));
  
  configStartAddr += 4;
  Serial.println("Preferences block flashed");
  return configStartAddr;
}


#endif
