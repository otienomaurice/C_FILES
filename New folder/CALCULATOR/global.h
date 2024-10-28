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
 //true if operand has been pressed
 extern bool operand_pressed;
 //true if the qual sign is pressed
 extern bool equal_pressed;
 extern int btnCnt = 0;
 //create an array to hold 16 buttons
 extern struct Button buttons[16];
//--------------------------------------------------------------------------------------
// concatenates the current display string with the input charact
void  update_Display(char text);
// updates the display  string
void  set_Display_Result(int32_t result);
// updates the display  string
void  set_Display_Error(char *text );
// clears the display string 
void  clear_global_Display();
// sets the two global operands to 0
void  clear_global_operands();
// sets the operator to invalid, this does nothing to calculation
void  clear_global_operator();
//clears every global variable
void clear_all();
//set global operator
void set_global_operator(char value);
//set global opernds
void set_global_operand1(int32_t value);
void set_global_operand1(int32_t value);
//adds the given value to the operands
void addToOpperand(int32_t *opperand, int value);
//updates the operator generically
void update_operator(char *operator, char value);
//----------------------------------------------------------------------------------------
#endif