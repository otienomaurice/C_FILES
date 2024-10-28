#include <inttypes.h>
#include <stdbool.h>
#ifndef CALCULATOR_H
#define CALCULATOR_H
//DEFINE THE CALCULATOR STRUCT
//DEFINE ENUMS FOR OPERATORS
enum OPERATOR
{
    ADD,
    SUB,
    MULT,
    DIV
};
 typedef struct 
{
    int32_t operand1;
    int32_t operand2;
    int32_t result;
    char operator;
    char display[30];
    bool hasError;
} Calculator;

//add
int32_t add( Calculator *calc);
//subtrac
int32_t sub(Calculator *calc);
//multiply
int32_t mult(Calculator *calc );
//divide
int32_t div(Calculator *calc );
//decode operator and calculate resul
void equals(Calculator *calc );
//clear the structure
void clear_calc(Calculator *calc );
//run arithmetic operation on the structure operands
int32_t calculate ( Calculator *calc,enum OPERATOR operator);


#endif // CALCULATOR_H