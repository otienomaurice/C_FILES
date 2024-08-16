#ifndef AVR_IO.C
#define AVR_IO.H
#include <inttypes.h>
//DEFINE THE SIZE OF THE PORTB REGISTER
//#define SIZE 8
////DEFINE THE ADDRESS OF THE PORTB REGISTER
#define PORTB_ADDRESS 0x450000
#define PORTB ((volatile uint8_t*)PORTB_ADDRESS)
////DEFINE THE ADDRESS OF THE PORTC REGISTER
#define PORTC_ADDRESS 0x450000
#define PORTC ((volatile uint8_t*)PORTC_ADDRESS)
////DEFINE THE ADDRESS OF THE PORTD REGISTER
#define PORTD_ADDRESS 0x450000
#define PORTD ((volatile uint8_t*)PORTD_ADDRESS)
//PORTB BITS
#define PORTB0 0
#define PORTB1 1
#define PORTB2 2
#define PORTB3 3
#define PORTB4 4
#define PORTB5 5
#define PORTB6 6
#define PORTB7 7
//PORTC BITS
#define PORTC0 0
#define PORTC1 1
#define PORTC2 2
#define PORTC3 3
#define PORTC4 4
#define PORTC5 5
#define PORTC6 6
#define PORTC7 7
//PORTD BITS
#define PORTD0 0
#define PORTD1 1
#define PORTD2 2
#define PORTD3 3
#define PORTD4 4
#define PORTD5 5
#define PORTD6 6
#define PORTD7 7
#endif
