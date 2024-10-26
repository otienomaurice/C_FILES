#include "pico/stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"
#include "ts_lcd.h"
#include "limits.h"
#include "button.h"
#include "timer.h"

//global state operands 
 float opperand1 = 0; 
 float opperand2 = 0; 
  //global state operator
 char  operator;
 //global state display
 //wilol be used to display all the text to the screen 
 char display[50];
//
int btnCnt = 0;
uint32_t current_time, button_debounce_time;
//create an array to hold 16 buttons
struct Button buttons[16];
//-----------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//initialize each button
void initButton(struct Button b)
{
    buttons[btnCnt] = b;
    btnCnt++;
}
//---------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
//updates the value of the operand
void addToOpperand(int32_t *opperand, int value)
{
    float result = *opperand * 10 + value;
    if (((*opperand > 0) && (result < *opperand)) || result > INT32_MAX)
    {
        return; // dont do anything because we are at the max number so just ignore the input
    }
    *opperand = result; // set the value
}
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//creates all buttons
void create_All_Buttons(){
    initButton(createButton(0, 40, 83, 50, '7'));
    initButton(createButton(83, 40, 83, 50, '8'));
    initButton(createButton(83 * 2, 40, 83, 50, '9'));
    initButton(createButton(0, 50 * 1 + 40, 83, 50, '4'));
    initButton(createButton(83, 50 * 1 + 40, 83, 50, '5'));
    initButton(createButton(83 * 2, 50 * 1 + 40, 83, 50, '6'));

    initButton(createButton(0, 50 * 2 + 40, 83, 50, '1'));
    initButton(createButton(83, 50 * 2 + 40, 83, 50, '2'));
    initButton(createButton(83 * 2, 50 * 2 + 40, 83, 50, '3'));
    initButton(createButton(0, 50 * 3 + 40, 83, 50, '0'));
    // the next set of buttons
    initButton(createButton(83 * 3, 50 * 0 + 40, 83, 50, '+'));
    initButton(createButton(83 * 3, 50 * 1 + 40, 83, 50, '-'));
    initButton(createButton(83 * 3, 50 * 2 + 40, 83, 50, '/'));
    initButton(createButton(83 * 3, 50 * 3 + 40, 83, 50, 'x'));
    initButton(createButton(83 * 2, 50 * 3 + 40, 83, 50, 'C'));
    initButton(createButton(83 * 1, 50 * 3 + 40, 83, 50, '='));
}
//---------------------------------------------------------------------------------------
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
                tick_button(&buttons[i], x, y, isTouched);
                button_debounce_time = current_time;
            }
        }
//check for evry button, if pressed add the value returned to operand
        for (int i = 0; i < btnCnt; i++)
        {
            if (buttons[i].pressed)
            {

                int value = buttons[i].c & 0b00001111;
                addToOpperand(&opperand1, (float)value);
            }
        }
//render all buttons on the screen
        for (int i = 0; i < btnCnt; i++)
        {
            render_button(&buttons[i]);
        }
//render the opernd on the screen
        render_text(display);

        
    }
}