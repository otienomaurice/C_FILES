#include "lcd.h"
int main(){

return 0;
}
//initialize i2c communication ports
void init(){
    // Set SDA and SCL pins as output
    DDRB |= (1 << SDA_PIN) | (1 << SCL_PIN);
    // Set SDA and SCL lines high (idle state)
    PORTB |= (1 << SDA_PIN) | (1 << SCL_PIN);
}
//begin communication
void begin(){
 PORTB |= (1 << SDA_PIN) | (1 << SCL_PIN); // Ensure SDA and SCL are high
    _delay_us(4); // Wait for a short time
    PORTB &= ~(1 << SDA_PIN); // Pull SDA low
    _delay_us(4); // Wait for a short time
    PORTB &= ~(1 << SCL_PIN); // Pull SCL low
}
int read(){
uint8_t data = 0;
    for (int8_t i = 7; i >= 0; i--) {
        PORTB |= (1 << SCL_PIN); // Set SCL high
        _delay_us(4); // Wait for a short time
        if (PINB & (1 << SDA_PIN)) {
            data |= (1 << i); // Read SDA value
        }
        PORTB &= ~(1 << SCL_PIN); // Set SCL low
        _delay_us(4); // Wait for a short time
    }
    // Send ACK after reading data
    PORTB &= ~(1 << SDA_PIN); // Send ACK (low)
    PORTB |= (1 << SCL_PIN);  // Set SCL high
    _delay_us(4); // Wait for a short time
    PORTB &= ~(1 << SCL_PIN); // Set SCL low
    return data;}
void write(uint8_t data){
  for (int8_t i = 7; i >= 0; i--) {
        if (data & (1 << i)) {
            PORTB |= (1 << SDA_PIN); // Set SDA high
        } else {
            PORTB &= ~(1 << SDA_PIN); // Set SDA low
        }
        _delay_us(4); // Wait for a short time
        PORTB |= (1 << SCL_PIN);  // Set SCL high
        _delay_us(4); // Wait for a short time
        PORTB &= ~(1 << SCL_PIN); // Set SCL low
    }
    // After sending data, wait for acknowledgment (usually check SCL line)}
void end(){
PORTB &= ~(1 << SDA_PIN); // Ensure SDA is low
    PORTB |= (1 << SCL_PIN);  // Pull SCL high
    _delay_us(4); // Wait for a short time
    PORTB |= (1 << SDA_PIN);  // Pull SDA high
    _delay_us(4); // Wait for a short time
}