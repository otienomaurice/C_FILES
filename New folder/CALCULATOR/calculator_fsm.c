#include <stdbool.h>
#include <stdlib.h>
#include "calculator.h"
#include "calculator_fsm.h"
#include "button.h"
#include "global.h"
#include "touchin_validation.h"
#include "display.h"
//initializes the calculator fsm
void init_calculator_fsm(){
     state = INITIAL_STATE;
     operand_pressed = false;
     equal_pressed = false;
     clear_pressed = false;
     input_operand2_complete;
     operator_first_press_before_operand = true;
     second_operator_pressed_after_operand2 false;
     negative_operand = false;
     clear_all();
     state = INITIAL_STATE;
}
//advance the fsm by one cycle 
void tick_calculator_fsm(){
   calc.operand1 =_global_opperand1;
   calc.operand2 = _global_opperand2;
   calc.operator = _global_operator;
    switch (state)
    {
    case INITIAL_STATE:
             operand_pressed = false;
             equal_pressed = false;
             clear_pressed = false;
             operator_first_press_before_operand = true;
             negative_operand = false;
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
                 display_text();
                 if(input_operand1_complete){
                 state = INPUT_OPERATOR;
                 }
                 else{
                 //this will either update the operands , the operator , or set clear pressed or equals pressed
                 char temp = button_info_fill();
                 update_Display(temp);
                 //check for negative
                 if(temp == '-' && operator_first_press_before_operand)
                 {
                 operator_pressed = false;
                 operator_first_press_before_operand = false;
                 clear_global_operator();
                 negative_operand = true;
                 }
                 //if button fill returns an operator, set the input to completed
                  //advance  to the operator state 
                if (operator_pressed){
                         if(negative_operand){
                            int32_t negate_operand1 = (0 - _global_opperand1);
                             set_global_operand1(negate_operand1);
                         }
                           input_operand1_complete = true;
                           state = INPUT_OPERATOR;
       }
         else {
                 state = INPUT_OPERAND1;
       }
                 }
     break;
   
     case INPUT_OPERATOR:
          display_text();
          operator_pressed = false;
          input_operand1_complete = false;
          state = INPUT_OPERAND2;
         break;
     case INPUT_OPERAND2:
         display_text();
         char temp = button_info_fill();
       if(clear_pressed){
         state = INITIAL_STATE;
        }
        else if(operator_pressed){
         second_operator_pressed_after_operand2 = true;
         input_operand1_complete = true;
         state = RUN_CALCULATION;
        }
       else  if (equal_pressed){

        state = RUN_CALCULATION;
      }
         break;
     case RUN_CALCULATION:
     display_text();
     if(second_operator_pressed_after_operand2){
        equals(&calc);
        if(calc.hasError)
           {
        //if error occurs, set the display to result
     set_Display_Error(calc.display);
     state = ERROR_STATE;
     }
     else{
          set_global_operand1(calc.result);
          second_operator_pressed_after_operand2 = false;
          state =INPUT_OPERAND1;
         }
     }
     //double check that equals pressed
     else if(equal_pressed){
      equals(&calc);
     }
        if(calc.hasError)
     {
        //if error occurs, set the display to result
     set_Display_Error(calc.display);
     state = ERROR_STATE;
     }
     else { 
        //update the display string to result
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