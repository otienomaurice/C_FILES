#ifdef LCD_H
#define LCD_H
#include <stdio.h>
#include <stdlib.h>
#include <stderr.h>
#include <string.h>
#include <inttypes.h>
#include "avr_io.h"
#endif
void begin(uint8_t address);
void init();
void write(uint8_t data);
uint_8 read();
void end();