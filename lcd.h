#ifdef LCD_H
#define LCD_H
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "avr_io.h"

//define the lcd address
#define LCD_ADDRESS 0x20
#define SDA_PIN PB4 
#define SCL_PIN PB5
//define methods to communicate with lcd
void begin(uint8_t address);
void init();
void write(uint8_t data);
uint8_t read();
void end();