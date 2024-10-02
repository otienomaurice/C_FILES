#include "alarm_intf.h"
#include "stdbool.h"
#include "pico/stdlib.h"
// Initialize the alarm interfaces 
void initAlarm(){
    //INITIALIZE THE GPIO PINS
     gpio_init(BUZZER);
     gpio_init(LED);
     gpio_init(SENSOR);

    //CONFIGURE BUZZER AS OUTPUT
     gpio_set_dir(BUZZER,1);
     //CONFIGURE LED AS OUTPUT
     gpio_set_dir(LED,1);
    //CONFIGURE LED AS OUTPUT
     gpio_set_dir(SENSOR,0);
    //ENABLE INTERNAL PULL UP ON SENSOR
     gpio_pull_up(SENSOR)
}
// Initialize the alarm interfaces void initAlarm();
uint8_t readDoor (){
//READ FROM THE SENSOR 
    bool on = !gpio_get(SENSOR);
    if(on)
      return 0xff;
    else 
      return 0x00;
}

// turn warning LED OFF 
void ledOff(){
     gpio_put(LED,0);
}

// turn warning LED ON
void ledOn (){
     gpio_put(LED,1);
}

// turn alarm buzzer OFF
 void alarmOff(){
     gpio_put(BUZZER,0);
 }

// turn alarm buzzer ON
 void alarmOn (){
     gpio_put(BUZZER,1);
 }
