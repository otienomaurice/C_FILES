#include <string.h>
#include "pico/stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"
#include "ts_lcd.h"
#include "limits.h"
#include "button.h"
#include "timer.h"
#include "global.h"

uint32_t current_time, button_debounce_time;



//---------------------------------------------------------------------------------------
//execute the main logic of the culator
void main()
{
 //initialize lcd display
ts_lcd_init();
//first create all buttons  
create_All_Buttons();
//get current time stamp
    current_time = timer_read();
//set timestamp for for all buttons 
    for (int i = 0; i < btnCnt; i++)
    {
        buttons[i].time = current_time;
    }

    while (1)
    {

        current_time = timer_read();
        uint16_t x, y;
        //assign the x and y coordinates to  x and y when touched and return true
        bool isTouched = get_ts_lcd(&x, &y);

        //
        for (int i = 0; i < btnCnt; i++)
        {
            if (timer_elapsed_ms(buttons[i].time, current_time) >= BUTTON_PRESSED_MS)
            {
            }
        }

                
                

                
            }
        }