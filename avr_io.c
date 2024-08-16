#include "avr_io.h"
#include <stdio.h>
int main(){
*PORTB = (uint8_t) 00010110;
uint8_t val = *PORTB;
//printf("%u\n",val);
int c = 8;
printf("%d\n",c);
return 0;
}