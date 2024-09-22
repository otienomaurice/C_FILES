#include "timer.h"
#include "avr_io.h"

volatile uint16_t overflow_count = 0;


// Timer1 overflow interrupt service routine
void __attribute__((interrupt)) TIMER1_OVF_vect() {
    overflow_count++;
}

void timer1_init() {
    // Set Timer1 to normal mode
    TCCR1A = 0x00;          // Normal mode
    TCCR1B = 0x00;          // Stop the timer

    // Set prescaler to 64
    TCCR1B |= (1 << CS11) | (1 << CS10);

    // Enable overflow interrupt
    TIMSK1 |= (1 << TOIE1);

    // Clear the overflow count
    overflow_count = 0;

    // Start the timer
    TCNT1 = 0; // Reset timer counter
}

void _delay_us(uint16_t us) {
    overflow_count = 0; // Reset overflow count
    while (overflow_count < us) {
        // Wait for the overflow count to reach the desired delay
    }
}