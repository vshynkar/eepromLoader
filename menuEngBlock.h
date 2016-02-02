#ifndef _MENU_EN_BLOCK_H
#define _MENU_EN_BLOCK_H

#ifdef __AVR__
#include <avr/io.h>
#include <avr/pgmspace.h>
#elif defined(ESP8266)
#include <pgmspace.h>
#else
#define PROGMEM
#endif

const char menuEnBlock[] PROGMEM = {
  ' ',  'M',  'o',  'd',  'e',  'm',  ' ' , 'C',  'o',  'n',  'f',  'i',  'g',  ' ',     // Modem Config
  ' ',  ' ',  'S',  'e',  'c',  'r',  'e',  't',  ' ',  'K',  'e',  'y',  ' ',  ' ',     // Secret Key
  ' ',  'M',  'e',  'm',  'o',  'r',  'y',  ' ',  'S',  'l',  'o',  't',  's',  ' ',     // Memory Slots
  0xCD, 0xF0, 0xE3, 0xE4, 0xEE, 0xBC, 0xD0, 0xDE, 0xEE, 0xBA, 0xFE, 0xF4, 0xFC, 0x20,    // Модем->Память
  0xCD, 0xF0, 0xE3, 0xE4, 0xEE, 0xBC, 0xC3, 0xEC, 0xF2, 0xDE, 0xEF, 0x20, 0x20, 0x20,    // Модем->Екран
  0xD0, 0xDE, 0xEE, 0xBA, 0xFE, 0xF4, 0xFC, 0xBC, 0xCD, 0xF0, 0xE3, 0xE4, 0xEE, 0x20,    // Память->Модем
  0xD0, 0xDE, 0xEE, 0xBA, 0xFE, 0xF4, 0xFC, 0xBC, 0xC3, 0xEC, 0xF2, 0xDE, 0xEF, 0x20,    // Память->Екран
  0x20, 0x20, 0x20, 0xD0, 0xF2, 0xF0, 0xF6, 0xE9, 0xED, 0xFC, 0x20, '1',  0x20, 0x20,    // Профіль 1
  0x20, 0x20, 0x20, 0xD0, 0xF2, 0xF0, 0xF6, 0xE9, 0xED, 0xFC, 0x20, '2',  0x20, 0x20,    // Профіль 2
  0x20, 0x20, 0x20, 0xD0, 0xF2, 0xF0, 0xF6, 0xE9, 0xED, 0xFC, 0x20, '3',  0x20, 0x20,    // Профіль 3
  0x20, 0x20, 0x20, 0xD0, 0xF2, 0xF0, 0xF6, 0xE9, 0xED, 0xFC, 0x20, '4',  0x20, 0x20,    // Профіль 4
  0x20, 0x20, 0x20, 0xD0, 0xF2, 0xF0, 0xF6, 0xE9, 0xED, 0xFC, 0x20, '5',  0x20, 0x20,    // Профіль 5
  0x20, 0x20, 0x20, 0xD0, 0xF2, 0xF0, 0xF6, 0xE9, 0xED, 0xFC, 0x20, '6',  0x20, 0x20,    // Профіль 6
  0xBF, 0xE8, 0xE3, 0xDE, 0xED, 0xE8, 0xF4, 0xE8, 0x20, 0xF5, 0xF3, 0xE9, 0x20, 0x20,    // Видалити усі
  0xBF, 0xE8, 0xE3, 0xDE, 0xED, 0xE8, 0xF4, 0xE8, 0x20, 0xF0, 0xE3, 0xE8, 0xEF, 0x20     // Видалити один

};

#endif
