#ifndef AVR_IO_H

#define AVR_IO_H 

#include <inttypes.h>
#include <stdint.h>
//DEFINE AVR-IO PINOUT
//PIN A
#define    PA0 0
#define    PA1 1
#define    PA2 2
#define    PA3 3
#define    PA4 4
#define    PA5 5
#define    PA6 6
#define    PA7 7
//PIN B
#define    PB0 0
#define    PB1 1
#define    PB2 2
#define    PB3 3
#define    PB4 4
#define    PB5 5
#define    PB6 6
#define    PB7 7
//PIN C
#define    PC0 0
#define    PC1 1
#define    PC2 2
#define    PC3 3
#define    PC4 4
#define    PC5 5
#define    PC6 6
#define    PC7 7
//PIN D
#define    PD0 0
#define    PD1 1
#define    PD2 2
#define    PD3 3
#define    PD4 4
#define    PD5 5
#define    PD6 6
#define    PD7 7
//DEFINE DATA DIRECTION REGISTERS
#define DDRA_ADDRESS 0X3A
#define DDRA ((volatile uint8_t*) DDRA_ADDRESS)
#define DDRB_ADDRESS 0X37
#define DDRB ((volatile uint8_t*) DDRB_ADDRESS)
#define DDRC_ADDRESS 0X34
#define DDRC ((volatile uint8_t*) DDRC_ADDRESS)
#define DDRD_ADDRESS 0X31
#define DDRD ((volatile uint8_t*) DDRD_ADDRESS)
//DEFINE DDRA REGISTER BITS
#define DDRA0 0
#define DDRA1 1
#define DDRA2 2
#define DDRA3 3
#define DDRA4 4
#define DDRA5 5
#define DDRA6 6
#define DDRA7 7
//DEFINE DDRB REGISTER BITS
#define DDRB0 0
#define DDRB1 1
#define DDRB2 2
#define DDRB3 3
#define DDRB4 4
#define DDRB5 5
#define DDRB6 6
#define DDRB7 7
//DEFINE DDRC REGISTER BITS
#define DDRC0 0
#define DDRC1 1
#define DDRC2 2
#define DDRC3 3
#define DDRC4 4
#define DDRC5 5
#define DDRC6 6
#define DDRC7 7
//DEFINE DDRD REGISTER BITS
#define DDRD0 0
#define DDRD1 1
#define DDRD2 2
#define DDRD3 3
#define DDRD4 4
#define DDRD5 5
#define DDRD6 6
#define DDRD7 7




//DEFINE THE SIZE OF THE PORTB REGISTER
////DEFINE THE ADDRESS OF THE PORTB REGISTER
#define PORTA_ADDRESS 0x3B
#define PORTA ((volatile uint8_t*)PORTA_ADDRESS)
////DEFINE THE ADDRESS OF THE PORTB REGISTER
#define PORTB_ADDRESS 0x38
#define PORTB ((volatile uint8_t*)PORTB_ADDRESS)
////DEFINE THE ADDRESS OF THE PORTC REGISTER
#define PORTC_ADDRESS 0x35
#define PORTC ((volatile uint8_t*)PORTC_ADDRESS)
////DEFINE THE ADDRESS OF THE PORTD REGISTER
#define PORTD_ADDRESS 0x32
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


// Define the register addresses for ATmega328P
#define TCCR1A (*(volatile uint8_t*)0x80) // Timer/Counter1 Control Register A
#define TCCR1B (*(volatile uint8_t*)0x81) // Timer/Counter1 Control Register B
#define TIMSK1 (*(volatile uint8_t*)0x6F)  // Timer/Counter Interrupt Mask Register 1
#define TCNT1 (*(volatile uint16_t*)0x84)  // Timer/Counter1



// Define relevant bits for TCCR1B
#define CS10 0 // Clock Select Bit 0
#define CS11 1 // Clock Select Bit 1
#define TOIE1 0 // Timer/Counter1 Overflow Interrupt Enable