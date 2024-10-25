#include <inttypes.h>
#include <stdbool.h>
#ifndef CALCULATOR_H
#define CALCULATOR_H

 typedef struct 
{
    int32_t operand1;
    int32_t operand2;
    float result;
    enum OPPERATOR operator;
    char display[30];
    bool hasError;
}Calculator;
enum OPPERATOR
{
    ADD,
    SUB,
    MUL,
    DIV,
    CLEAR,
    EQUAL,
};

float add( Calculator *calc);
float sub(Calculator *calc);
float mult(Calculator *calc );
float div(Calculator *calc );
void calculate ( float (*operation)( Calculator *calc ),Calculator *calc);

#endif