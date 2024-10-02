#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include "alarm_intf.h"
//warning signal
bool warn_g;
//timer_30s signal
bool timer_30;
 //STATES
 //DOOR_CLOSED - DOOR IS CLOSED NO LED FLASHING, ALRM IS OFF
 //DOOR_OPEN - LED FLASHING ONCE EVERY SECOND, ALARM IS OFF
 //DOOR_OPEN30 - DOOR OPEN LONGER THAN 30S - ALARM IS ON, LED FLASHING
 typedef enum { DOOR_CLOSED, DOOR_OPEN, DOOR_OPEN30 } ALARM_STATE;
 //
 static ALARM_STATE state;
//initialize alarm state 
void alarm_init(){
    state = DOOR_CLOSED;
    warn_g = false;
    alarmOff(); 
}

//ticks the alarm fsm
void tick_alarm_fsm(){
    //read door sensor
    uint8_t sensor_data = readSensor();
    //convert sensor data to boolean - why specification used uint8_t readSensor but i'm only checking if sensor is on or off
    bool sw_mode = (sensor_data >0)?true:false;
    //read timer30 value
    timer_30 = timer30s_passed();
switch(state){
case DOOR_CLOSED:
     //warning signal off
     warn_g = false;
     alarmOff();
    if(sw_mode)
     state = DOOR_OPEN;
     else 
     state = DOOR_CLOSED
     break;
case DOOR_OPEN:
     warn_g = true;
    if(sw_mode &&timer_30)
     state = DOOR_OPEN30;
     else if (sw_mode&& !timer_30)
     state = DOOR_OPEN
     else
     state = DOOR_CLOSED;
     break;
case DOOR_OPEN30:
     alarmOn();
     if(sw_mode)
     state = DOOR_OPEN30;
     else
     state = DOOR_CLOSED;
     break;
default:
     state = DOOR_CLOSED;
     alarmOff();
     warn_g = false;
     break;
    }
}
bool alarm_warn_g (){
    return warn_g;
}