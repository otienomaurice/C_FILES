#ifndef CALCULATOR_FSM.C
#define CALCULATOR_FSM.C
#include <stdbool.h>
#include <stdlib.h>
#include "global.h"
//This fsm is responsible for handling th e states of the calculation
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
void init_calculation_fsm();
//advance the fsm by one cycle 
void tick_calculation_fsm();
#endif