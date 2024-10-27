#ifndef GLOBAL_H
#define GLOBAL_H
#include <string.h>
#include <inttypes.h>
//global state operands 
 extern int32_t _global_opperand1; 
 extern int32_t _global_opperand2 ; 
  //global state operator
 extern char  _global_operator;
 //global state display
 //wilol be used to display all the text to the screen 
 extern char _global_display[50];
//
//true if C (Clear) is pressed
 extern bool clear_pressed;
 //true if an error is detected
 extern bool error;
 //true if operator has been typed in
extern bool operator_pressed;
 //true if operand has completly been typed in
 extern bool operand_pressed;
 //true if the qual sign is pressed
extern bool equal_pressed;
 //true if expecting operand1
 extern bool input_operand1;
 //true if true if expecting operand2
 extern bool input_operand2;
extern int btnCnt = 0;
//create an array to hold 16 buttons
extern struct Button buttons[16];
//--------------------------------------------------------------------------------------
// updates the display  string
void  update_Display(char *text);
// clears the display string 
void  clear_global_Display();
// sets the two global operands to 0
void  clear_global_operands();
// sets the operator to invalid, this does nothing to calculation
void  clear_global_operands();
//clears every global variable
void clear_all();
//set global operator
void set_global_operator(){}
//set global opernds
void set_global_operand1(){}
void set_global_operand1(){}
//adds the given value to the operands
void addToOpperand(int32_t *opperand, int value);
//
//updates the operator globally
void update_operator();
//----------------------------------------------------------------------------------------
#endif