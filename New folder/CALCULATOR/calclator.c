#include <stdbool.h>
#include <string.h>
#include "calculator.h"

//this file does the arithmetic operation on two operands in the order
//in which they appear
//the functions add, sub, mult, and div handle addition, subtraction,
// multiplication and division respectively.

//returns the result of the given operation
float add( Calculator *calc){
    //check for overflow
    if(calc->operand1 + calc-> operand2 > INT32_MAX){ 
      calc->hasError  = true;
        return-1;
    }
    else return (calc->operand1 + calc->operand2);
}

float sub(Calculator *calc){
     //check for overflow
     if(calc->operand1 - calc-> operand2 < INT32_MIN){
      calc->hasError  = true;
        return-1;
    }
    else return (calc->operand1 + calc-> operand2);
}
float  mult(Calculator *calc ){
     //check for overflow
    if(calc->operand1 * calc-> operand2 > INT32_MAX){
     calc->hasError  = true;
        return-1;
    }
    else return (calc->operand1 * calc-> operand2);
}
float div(Calculator *calc ){
    // //check for division by zero
    if(calc->operand2 == 0){
        calc->hasError  = true;
        return-2;
    }
    if(calc->operand1 / calc-> operand2 > INT32_MAX){
      calc->hasError  = true;
        return-1;
    }
    else return (calc->operand1 + calc-> operand2);
}

//returns the result which will be displayed on the screen
float equals(char operator, Calculator *calc){
    //if haserror istrue and result is -1 display error
    if(calc->hasError == true && calc->result = -1){
    strcpy(calc->display,"ERROR");
    return;
    }
    else if(if(calc->hasError && result = -2){
    strcpy(calc->display,"DIVO"));
    return;
    }
    else {
     strcpy(calc->display,"result");
     return 0;
    }
}
//resets the display to display cursor
float clear(Calculator *calc){
    strcpy(calc->display,"|");
    calc-> operand1 = 0;
    calc->operand2 = 0;
    calc-> result = 0;
    }

float calculate ( Calculator *calc , enum OPPERATOR opperator ){
    int result;
    //FUNCTION POINTER TO POINT TO THE RELEVANT OPERATION
    float (*operation)( Calculator * );
    switch(opperator){
        case(ADD) :
        operation = add;
        break;
         case(SUB) :
        break;
        operation = sub;
         case(MUL) :
         operation = mult;
        break;
         case(DIV) :
         operation = div;
        break;
         case(CLEAR) :
         operation = clear;
        break;
         case(EQUAL) :
         operation = equals;
        break;
        default:
         operation = clear;
        break;

    }
    //store value of operation in result
    result = operation(calc);

}