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


int32_t add( Calculator *calc);
int32_t sub(Calculator *calc);
int32_t mult(Calculator *calc );
int32_t div(Calculator *calc );
void equals(Calculator *calc );
void clear(Calculator *calc );
int32_t calculate ( Calculator *calc,enum OPERATOR operator);


#endif // CALCULATOR_H