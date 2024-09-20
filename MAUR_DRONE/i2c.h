#include <inttypes.h>

#ifndef I2C_H
#define I2C_H
#endif

void init_i2c();
void start_i2c();
void end_12c();
void write_12c();
uint8_t read_12c();
