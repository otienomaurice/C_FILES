#include <stdlib.h>
#include <stdbool.h>
#include "alarm_intf.h"
typedef bool boolean;
//declare states for warning on and warning off
//IN WRNOFF LED IS OFF
//IN WRNON LED IS ON
typedef enum {WRNOFF, WRNON}ALARM_STATE;
//
static ALARM_STATE state;
//initialize alarm
void warn_init(){
    current_state =  WRNOFF;
    ledOff();
}
//ticks the fsm every period
void tickFct_WARNFSM(){
    //read alarm warning value
    boolean warn_g = alarm_warn_g(); 
    switch(state){
        case WRNOFF:
        //TURN OFF LED
             ledOff();
          if(warn_g)
             state = WRNON;
          else 
             state = WRNOFF;
        break;

        case WRNOFF:
        //TURN ON LED
             ledOn();
             state = WRNOFF;
        break;
         default WRNOFF:
             state = WRNOFF;
             ledOff();
        break;
    }

}