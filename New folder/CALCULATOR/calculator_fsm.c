#include <stdbool.h>
#include <stdlib.h>
#include "calculator.h"
#include "calculation_fsm.h"
#include "button.h"
#include "global.h"
#include "touchin_validation.h"
// //instatiate the global state variables
//   int32_t _global_opperand1 ; 
//   int32_t _global_opperand2 ; 
//   char  _global_operator;
// //initialize global state dsiplay
//   char _global_display[50] = "|";
//initializes the calculator fsm
//period of button press

void init_calculation_fsm(){
    state = INITIAL_STATE;
    operand_pressed = false;
    equal_pressed = false;
    clear_pressed = false;
    error = false;
}

//advance the fsm by one cycle 
void tick_calculation_fsm(){
    //get the required operands and operators

    //do the reading stuff and setting required variables
    switch (state)
    {
    case INITIAL_STATE:
             operand_pressed = false;
             equal_pressed = false;
             clear_pressed = false;
             error = false;
        //clear the global variables setting them to zero
              clear_all();
        //update state 
             if(clear_pressed)
                 state = INITIAL_STATE;
             else 
                 state = INPUT_OPERAND;
     break;

    case INPUT_OPERAND:
       button_info_fill();
        break;

    
        case ERROR_STATE:
 
        break;

    
        case RUN_CALCULATION:
        /* code */
        break;
    
    default:
        break;
    }
}