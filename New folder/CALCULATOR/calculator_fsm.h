#ifndef CALCULATOR_FSM.C
#define CALCULATOR_FSM.C
#include <stdbool.h>
#include <stdlib.h>
//This fsm is responsible for handling th e states of the calculation
  //initialize calculator with desired values
  //true if operand1 is complete
 static bool input_operand1_complete;
//
static bool input_operand2_complete;
 //checks if the - operator haas been pressed before an operand denoting a negative inpu
 static bool operator_first_press_before_operand;
 //set true if the keyed operand is negative
 //second operator pressed after second operand
 static bool second_operator_pressed_after_operand2;
 static bool negative_operand;
 //
  static Calculator calc ; 
//THERE ARE FIVE STATES FOR THE CALCULATOR
typedef enum { INITIAL_STATE, 
        INPUT_OPERAND1,
        INPUT_OPERATOR,
        INPUT_OPERAND2,
        ERROR_STATE,
        RUN_CALCULATION,
        DISPLAY_STATE 
 } CALCULATOR_STATE;

static CALCULATOR_STATE state;
//initialize the calculation fsm
void init_calculator_fsm();
//advance the fsm by one cycle 
void tick_calculator_fsm();
#endif