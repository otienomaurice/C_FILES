
#include <stdlib.h>
#include "pico/stdlib.h"
#include "inttypes.h"
#include  "ztimer.h"
#include  "alarm_intf.h"
//define the periods 
#define ALRMFSM_PERIOD_ms 1000000
#define WRNFSM_PERIOD_ms 1000000
#define time
volatile bool timer30_passed;
int main(){
timer30_passed = 0;
uint32_t time_start = timer_read();
uint32_t time_30;
uint32_t time_alarm_fsm;
uint32_t time_warn_fsm;
   //initialize the system
   warn_init();
   alarm_init();
   //
    while(1){
if(timer_elapsed_us() )

    }
     return 0;
}
bool timer30s_passed(){
    return timer30_passed;
}