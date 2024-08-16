#ifdef LCD_H
#define LCD_H
#include <stdio.h>
#include <stdlib.h>
#include <stderr.h>
#include <string.h>
#include <inttypes.h>
#include "avr_io.h"
#endif
//define the lcd address
#define LCD_ADDRESS 0x20
//define mwthods to communicate with lcd
void begin(uint8_t address);
void init();
void write(uint8_t data);
uint_8 read();
void end();