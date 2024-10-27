#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "calculator.h"


//this file does the arithmetic operation on two operands in the order
//in which they appear
//the functions add, sub, mult, and div handle addition, subtraction,
// multiplication and division respectively.
//they return the corresponding results and if no error occurs, a -1 
//if any other error occurs and a -2 for division by zero error
//--------------------------------------------------------------------------------
//add the two operands
int32_t add( Calculator *calc){
    //check for overflow
    if(calc->operand1 + calc-> operand2 > INT32_MAX){ 
      calc->hasError  = true;
        return-1;
    }
    else return (calc->operand1 + calc->operand2);
}
//----------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------
//SUBTRACT THE TWO OPERANDS
int32_t sub(Calculator *calc){
     //check for overflow
     if((calc->operand1 - calc-> operand2 )< INT32_MIN){
      calc->hasError  = true;
        return-1;
    }
    else return (calc->operand1 - calc-> operand2);
}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
//MULTIPLY THE TWO OPERANDS, 
int32_t  mult(Calculator *calc ){
     //check for overflow
    if(calc->operand1 * calc-> operand2 > INT32_MAX){
     calc->hasError  = true;
        return-1;
    }
    else return (calc->operand1 * calc-> operand2);
}
//--------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------
//devide the two numbers
//first check for division by zero
//then check for overflow
//if all conditions passed, return the divion of the first with the second operand respectively
int32_t div(Calculator *calc ){
    //check for division by zero
    if (calc->operand2 == 0){
        calc->hasError  = true;
        return-2;
    }
    //check for overflow
    else if(calc->operand1 == INT32_MIN && calc-> operand2 ==  -1){
      calc->hasError  = true;
        return-1;
    }
    else return (calc->operand1 / calc-> operand2);
}
//--------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------
//returns the result which will be displayed on the screen
void equals(Calculator *calc){
    //PASS THE CORRESPONDING ARITHMETIC OPERATION
    switch(calc->operator){
      case '+':
      calc->result = calculate(calc,ADD);
      if(calc-> hasError && calc-> result < 0)
      strcpy(calc->display,"ERROR!"); 
         break;
     case '-':
       calc->result = calculate(calc,SUB);
       if(calc-> hasError && calc-> result < 0)
      strcpy(calc->display,"ERROR!"); 
         break;
     case 'x':
       calc->result = calculate(calc,MULT);
       if(calc-> hasError && calc-> result < 0)
      strcpy(calc->display,"ERROR!"); 
         break;
     case '/':
       calc->result = calculate(calc,DIV);
       if(calc-> hasError && calc-> result == -2)
      strcpy(calc->display,"DIV0!"); 
          break;
    default:
        //nop
        break;
    }
}
//------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//resets the display to display cursor
void clear(Calculator *calc){
    strcpy(calc->display,"|");
    calc-> operand1 = 0;
    calc->operand2 = 0;
    calc-> result = 0;
    calc->operator ='|';
    calc->hasError = false;
    }
//-----------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------
int32_t calculate ( Calculator *calc , enum OPERATOR operator ){
    //FUNCTION POINTER TO POINT TO THE RELEVANT OPERATION
    int32_t (*operation)( Calculator * );
    switch(operator){
        case(ADD) :
        operation = add;
        break;
         case(SUB) :
        operation = sub;
        break;
         case(MULT) :
         operation = mult;
        break;
         case(DIV) :
         operation = div;
        break;
         default:
         //NOP
         ;
         break;
    }
    //return the result
     return  operation(calc);
}
//-----------------------------------------------------------------------------------------
