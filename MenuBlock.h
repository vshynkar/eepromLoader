#ifndef _MENU_BLOCK_H
#define _MENU_BLOCK_H

#ifdef __AVR__
#include <avr/io.h>
#include <avr/pgmspace.h>
#elif defined(ESP8266)
#include <pgmspace.h>
#else
#define PROGMEM
#endif

#include "I2C_eeprom.h"

#define MENU_LINE_LENGTH          14

const char menuEnBlock[] PROGMEM = {
  'M',  'o',  'd',  'e',  'm',  ' ' , 'C',  'o',  'n',  'f',  'i',  'g',  ' ',  ' ',     // 0.  Modem Config
  'S',  'e',  'c',  'r',  'e',  't',  ' ',  'K',  'e',  'y',  ' ',  ' ',  ' ',  ' ',     // 1.  Secret Key
  'M',  'e',  'm',  'o',  'r',  'y',  ' ',  'S',  'l',  'o',  't',  's',  ' ',  ' ',     // 2.  Memory Slots
  'M',  'o',  'd',  'e',  'm',  0xBC, 'M',  'e',  'm',  'o',  'r',  'y',  ' ',  ' ',     // 3.  Modem->Memory
  'M',  'o',  'd',  'e',  'm',  0xBC, 'S',  'c',  'r',  'e',  'e',  'n',  ' ',  ' ',     // 4.  Modem->Screen
  'M',  'e',  'm',  'o',  'r',  'y',  0xBC, 'M',  'o',  'd',  'e',  'm',  ' ',  ' ',     // 5.  Memory->Modem
  'M',  'e',  'm',  'o',  'r',  'y',  0xBC, 'S',  'c',  'r',  'e',  'e',  'n',  ' ',     // 6.  Memory->Screen
  ' ',  ' ',  ' ',  'M',  'e',  'm',  ' ',  'S',  'l',  'o',  't',  ' ',  '1',  ' ',     // 7.  Mem Slot 1
  ' ',  ' ',  ' ',  'M',  'e',  'm',  ' ',  'S',  'l',  'o',  't',  ' ',  '2',  ' ',     // 8.  Mem Slot 2
  ' ',  ' ',  ' ',  'M',  'e',  'm',  ' ',  'S',  'l',  'o',  't',  ' ',  '3',  ' ',     // 9.  Mem Slot 3
  ' ',  ' ',  ' ',  'M',  'e',  'm',  ' ',  'S',  'l',  'o',  't',  ' ',  '4',  ' ',     // 10. Mem Slot 4
  ' ',  ' ',  ' ',  'M',  'e',  'm',  ' ',  'S',  'l',  'o',  't',  ' ',  '5',  ' ',     // 11. Mem Slot 5
  ' ',  ' ',  ' ',  'M',  'e',  'm',  ' ',  'S',  'l',  'o',  't',  ' ',  '6',  ' ',     // 12. Mem Slot 6
  'D',  'e',  'l',  'e',  't',  'e',  ' ',  'A',  'l',  'l',  ' ',  ' ',  ' ',  ' ',     // 13. Delete All
  'D',  'e',  'l',  'e',  't',  'e',  ' ',  'O',  'n',  'e',  ' ',  ' ',  ' ',  ' ',     // 14. Delete One
  'P',  'r',  'e',  'f',  'e',  'r',  'e',  'n',  'c',  'e',  's',  ' ',  ' ',  ' ',     // 15. Preferences
  'L',  'a',  'n',  'g',  'u',  'a',  'g',  'e',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',     // 16. Language
  'S',  'e',  'r',  'i',  'a',  'l', ' ',   'S',  'p',  'e',  'e',  'd',  ' ',  ' ',     // 17. Serial Speed
  0xD4, 0xEC, 0xF2, 0xDE, 0xEA, 0xEF, 0xF3, 0xFC, 0xEC, 0xDE, ' ',  ' ',  ' ',  ' ',     // 18. Українська
  'E',  'n',  'g',  'l',  'i',  's',  'h',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',     // 19. English
  '1',  '9',  '2',  '0',  '0',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',     // 20. 19200
  '2',  '8',  '8',  '0',  '0',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',     // 21. 28800
  '3',  '1',  '2',  '5',  '0',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',     // 22. 31250
  '3',  '8',  '4',  '0',  '0',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',     // 23. 38400
  '5',  '7',  '6',  '0',  '0',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',     // 24. 57600
  '1',  '1',  '5',  '2',  '0',  '0',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',     // 25. 115200
  ' ',  ' ',  ' ',  ' ',  'S',  'a',  'v',  'e',  'd',  '!',  ' ',  ' ',  ' ',  ' ',     // 26. Saved!
  ' ',  ' ',  ' ',  'R',  'e',  'a',  'd',  'i',  'n',  'g',  ' ',  ' ',  ' ',  ' ',     // 27. Reading
  ' ',  ' ',  ' ',  'D',  'e',  'l',  'e',  't',  'e',  'd',  '!',  ' ',  ' ',  ' '      // 28. Deleted!

};

const char menuUaBlock[] PROGMEM = {
  0xCB, 0xF0, 0xEF, 0xF6, 0xE9, 0xE1, ' ',  0xEE, 0xF0, 0xE3, 0xE4, 0xEE, 0xDE, ' ',     // 0.  Конфіг модема
  0xD2, 0xE4, 0xEC, 0xF2, 0xE4, 0xF4, 0xEF, 0xE8, 0xEB, ' ',  0xEc, 0xED, 0xFD, 0xF9,    // 1.  Секретний ключ
  0xD0, 0xF2, 0xF0, 0xF6, 0xE9, 0xED, 0xE9, ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',     // 2.  Профілі
  0xCD, 0xF0, 0xE3, 0xE4, 0xEE, 0xBC, 0xD0, 0xDE, 0xEE, 0xBA, 0xFE, 0xF4, 0xFC, ' ',     // 3.  Модем->Память
  0xCD, 0xF0, 0xE3, 0xE4, 0xEE, 0xBC, 0xC3, 0xEC, 0xF2, 0xDE, 0xEF, ' ',  ' ',  ' ',     // 4.  Модем->Екран
  0xD0, 0xDE, 0xEE, 0xBA, 0xFE, 0xF4, 0xFC, 0xBC, 0xCD, 0xF0, 0xE3, 0xE4, 0xEE, ' ',     // 5.  Память->Модем
  0xD0, 0xDE, 0xEE, 0xBA, 0xFE, 0xF4, 0xFC, 0xBC, 0xC3, 0xEC, 0xF2, 0xDE, 0xEF, ' ',     // 6.  Память->Екран
  ' ',  ' ',  ' ',  0xD0, 0xF2, 0xF0, 0xF6, 0xE9, 0xED, 0xFC, ' ',  '1',  ' ',  ' ',     // 7.  Профіль 1
  ' ',  ' ',  ' ',  0xD0, 0xF2, 0xF0, 0xF6, 0xE9, 0xED, 0xFC, ' ',  '2',  ' ',  ' ',     // 8.  Профіль 2
  ' ',  ' ',  ' ',  0xD0, 0xF2, 0xF0, 0xF6, 0xE9, 0xED, 0xFC, ' ',  '3',  ' ',  ' ',     // 9.  Профіль 3
  ' ',  ' ',  ' ',  0xD0, 0xF2, 0xF0, 0xF6, 0xE9, 0xED, 0xFC, ' ',  '4',  ' ',  ' ',     // 10. Профіль 4
  ' ',  ' ',  ' ',  0xD0, 0xF2, 0xF0, 0xF6, 0xE9, 0xED, 0xFC, ' ',  '5',  ' ',  ' ',     // 11. Профіль 5
  ' ',  ' ',  ' ',  0xD0, 0xF2, 0xF0, 0xF6, 0xE9, 0xED, 0xFC, ' ',  '6',  ' ',  ' ',     // 12. Профіль 6
  0xBF, 0xE8, 0xE3, 0xDE, 0xED, 0xE8, 0xF4, 0xE8, ' ',  0xF5, 0xF3, 0xE9, ' ',  ' ',     // 13. Видалити усі
  0xBF, 0xE8, 0xE3, 0xDE, 0xED, 0xE8, 0xF4, 0xE8, ' ',  0xF0, 0xE3, 0xE8, 0xEF, ' ',     // 14. Видалити один
  0xCB, 0xF0, 0xEF, 0xF6, 0xE9, 0xE1, 0xF5, 0xF2, 0xDE, 0xF8, 0xE9, 0xEA, ' ',  ' ',     // 15. Конфігурації
  0xCD, 0xF0, 0xE0, 0xDE, ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',     // 16. Мова
  0xD8, 0xDE, 0xF3, 0xF4, 0xF0, 0xF4, 0xDE, ' ',  0xD0, 0xF0, 0xF2, 0xF4, 0xDE, ' ',     // 17. Частота Порта
  0xD4, 0xEC, 0xF2, 0xDE, 0xEA, 0xEF, 0xF3, 0xFC, 0xEC, 0xDE, ' ',  ' ',  ' ',  ' ',     // 18. Українська
  'E',  'n',  'g',  'l',  'i',  's',  'h',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',     // 19. English
  '1',  '9',  '2',  '0',  '0',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',     // 20. 19200
  '2',  '8',  '8',  '0',  '0',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',     // 21. 28800
  '3',  '1',  '2',  '5',  '0',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',     // 22. 31250
  '3',  '8',  '4',  '0',  '0',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',     // 23. 38400
  '5',  '7',  '6',  '0',  '0',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',     // 24. 57600
  '1',  '1',  '5',  '2',  '0',  '0',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',     // 25. 115200
  ' ',  ' ',  0xC6, 0xDF, 0xE4, 0xF2, 0xE4, 0xE6, 0xE4, 0xEF, 0xF0, '!',  ' ',  ' ',     // 26. Збережено!
  ' ',  ' ',  0xC6, 0xF9, 0xE8, 0xF4, 0xF5, 0xE0, 0xDE, 0xEF, 0xEF, 0xFE, ' ',  ' ',     // 27. Зчитування
  ' ',  ' ',  0xBF, 0xE8, 0xE3, 0xDE, 0xED, 0xE4, 0xEF, 0xF0, '!',  ' ',  ' ',  ' '      // 28. Видалено!

};

int getMenuRowsCount(void) {
  return sizeof(menuUaBlock) / MENU_LINE_LENGTH;
}

int getMenuByteCount(void) {
  return sizeof(menuUaBlock);
}

uint16_t writeMenu(uint16_t addrOffset, I2C_eeprom* ee, uint16_t configAddr, const char* progmem, bool showData) {
  ee->writeInt(configAddr, addrOffset);

  int menuRows = getMenuRowsCount();
  char data;
  char testdata;
  for (int i = 0; i < menuRows; i++) {
    for (int j = 0; j < MENU_LINE_LENGTH; j++) {
      data = (char) pgm_read_byte(progmem + i * MENU_LINE_LENGTH + j);
      testdata = (char) ee->readByte(addrOffset + i * MENU_LINE_LENGTH + j);
      if (testdata != data) {
        ee->writeByte(addrOffset + i * MENU_LINE_LENGTH + j, data);
      }
    }
  }

  Serial.println("Menu message block flashed");
  addrOffset += getMenuByteCount();
  return addrOffset;
}

uint16_t writeMenuUa(uint16_t addrOffset, I2C_eeprom* ee, bool showData) {
  return writeMenu(addrOffset, ee, MENU_UA_BLOCK_ADDR, menuUaBlock, showData);
}

uint16_t writeMenuEn(uint16_t addrOffset, I2C_eeprom* ee, bool showData) {
  return writeMenu(addrOffset, ee, MENU_EN_BLOCK_ADDR, menuEnBlock, showData);
}


#endif
