
#include "pico/stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"
#include "ts_lcd.h"
#include  "inttypes.h"
#include "button.h"
#include "timer.h"
#include "global.h"
#include "display.h"
#include  "calculator_fsm.h"

uint32_t current_time, button_debounce_time;
int btnCnt = 0;
struct Button buttons[16];
char _global_display[50];
  int32_t _global_opperand1; 
  int32_t _global_opperand2 ; 
  //global state operator
  char  _global_operator;
 //global state display
 //wilol be used to display all the text to the screen 
  char _global_display[50];
 //
  //true if C (Clear) is pressed
  bool clear_pressed;
 //true if an error is detected
  bool error;
 //true if operator has been typed in
  bool operator_pressed;
 //true if operand has been pressed
  bool operand_pressed;
 //true if the qual sign is pressed
  bool equal_pressed;
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
 //
 init_calculator_fsm();
//set timestamp for for all buttons 
    for (int i = 0; i < btnCnt; i++)
    {
        buttons[i].time = current_time;
    }

    while (1)
    {   //display the buttons
       display_bottons();
       //
       display_text();
        //  //
        int tick_time = timer_read();
           if (timer_elapsed_ms(tick_time, current_time) >= BUTTON_PRESSED_MS)
            {
        tick_calculator_fsm();
        current_time = tick_time;
          }
        }
                
       
    }
        

