
#ifndef ALARM_INTF_H
#define ALARM_INTF_H
#include "pico/stdlib.h"
#include <inttypes.h>
//connect buzzer to pin 25
#define BUZZER 25
//connect door sensor to pin 11
#define SENSOR 11
//connect LED  tp pin 25
#define LED    26
// Initialize the alarm interfaces 
void initAlarm(){}
//read door sensor
uint8_t readDoor ();
// turn warning LED OFF 
void ledOff();
// turn warning LED ON
void ledOn ();
// turn alarm buzzer OFF
 void alarmOff();
// turn alarm buzzer ON
 void alarmOn ();
#endif
