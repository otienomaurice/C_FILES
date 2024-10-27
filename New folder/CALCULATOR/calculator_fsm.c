#include <stdbool.h>
#include <stdlib.h>
#include "calculator.h"
#include "calculator_fsm.h"
#include "button.h"
#include "global.h"
#include "touchin_validation.h"
#include "display.h"
// //instatiate the global state variables
//   int32_t _global_opperand1 ; 
//   int32_t _global_opperand2 ; 
//   char  _global_operator;
// //initialize global state dsiplay
//   char _global_display[50] = "|";
//initializes the calculator fsm
//period of button press

void init_calculator_fsm(){
    state = INITIAL_STATE;
    operand_pressed = false;
    equal_pressed = false;
    clear_pressed = false;
    error = false;
    operator_first_press_before_operand = true;
    clear_all();
}

//advance the fsm by one cycle 
void tick_calculator_fsm(){
    //get the required operands and operators

    //do the reading stuff and setting required variables
    switch (state)
    {
    case INITIAL_STATE:
             operand_pressed = false;
             equal_pressed = false;
             clear_pressed = false;
             error = false;
             operator_first_press_before_operand = true;
        //clear the global variables setting them to zero
         clear_all();
        //DSIPLAY CURSOR
        display_text();
        //update state 
             if(clear_pressed)
                 state = INITIAL_STATE;
             else 
                 state = INPUT_OPERAND1;
     break;

    case INPUT_OPERAND1:
    //if button fill returns an operator, set the input to completed
    //advance  to the operator state
    display_text();
    //this will either update the operands , the operator , or set clear pressed or equals pressed
    char temp = button_info_fill();
     //check for negative
     if(temp == '-' && operator_first_press_before_operand)
     {
        update_Display(temp);
        operator_pressed = false;
        operator_first_press_before_operand = false;
        //clear global operator
        clear_global_operator();
        //set the
     }
       if (operator_pressed){
       input_operand1_complete = true;
       state = INPUT_OPERATOR;
       }
       else 
       state = INPUT_OPERAND1;
        break;
   
    case INPUT_OPERATOR:
     char temp = button_info_fill();
     //UPDATE DISPLAY
     update_Display(temp);
     display_text();
    if( operator_pressed && input_operand1_complete ){
    state = INPUT_OPERAND2;
    }
    else state = INPUT_OPERATOR;
         break;
     case INPUT_OPERAND2:
       char temp = button_info_fill();
       if(clear_pressed){
         state = INITIAL_STATE;
        }
       else  if (equal_pressed){

        state = RUN_CALCULATION;
      }
         break;
    case RUN_CALCULATION:
    display_text();
//double check that equals pressed
    if(equal_pressed){
      equals(&calc);
    }
        if(calc.hasError)
    {
        //if error occurs, set the display to result
    set_Display_Error(calc.display);
    state = ERROR_STATE;
    }
     else {
        //update the display to display result
    set_Display_Result(calc.result);
    state = INPUT_OPERAND1;
}
         break;
    case ERROR_STATE:
      display_text();
      if(clear_pressed)
      state = INITIAL_STATE;
      else {
        state = ERROR_STATE;
      }
         break;
    default:
         break;
    }
}