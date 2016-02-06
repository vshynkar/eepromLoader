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
  'P',  'o',  'r',  't',  ' ',  'S',  'p',  'e',  'e',  'd',  ' ',  ' ',  ' ',  ' ',     // 17. Port Speed
  0xD4, 0xEC, 0xF2, 0xDE, 0xEA, 0xEF, 0xF3, 0xFC, 0xEC, 0xDE, ' ',  ' ',  ' ',  ' ',     // 18. Українська
  'E',  'n',  'g',  'l',  'i',  's',  'h',  ' ',  ' ',  ' ',  ' ',  ' ',  ' ',  ' '      // 19. English

};

#endif
