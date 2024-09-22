// delay.h

#ifndef DELAY_H
#define DELAY_H

#include <stdint.h>

// Define F_CPU for delay calculations
#define F_CPU 16000000UL // Set to your microcontroller's frequency

// Function prototypes
void timer1_init();
void _delay_us(uint16_t ms);

#endif // DELAY_H