#include <string.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "ts_lcd.h"
#include "button.h"
#include "global.h"
#include "calculator.h"

//  int32_t _global_opperand1; 
//  int32_t _global_opperand2 ; 
//  char  _global_operator;
//--------------------------------------------------------------------------------------
// concatenates the current string with the input charact
void  update_Display(char text){
strcat(_global_display,text);
}
//---------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
// updates the display  string
void  set_Display_Result(int32_t result){
sprintf(_global_display,"%d",result);
}
//---------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
// updates the display  string
void  set_Display_Error(char *text ){
strcpy(_global_display,text);
}
//---------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
// clears the display string 
void clear_global_Display(){
strcpy(_global_display," ");
}
//---------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------
// sets the two global operands to 0
void clear_global_operands(){
_global_opperand1 = 0;
_global_opperand2 = 0;
}
//---------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------
// sets the operator to invalid, this does nothing to calculation
void  clear_global_operator(){
 _global_operator = '|';
}
//----------------------------------------------------------------------------------------
//clear verything global
void clear_all(){
     clear_global_Display();
     clear_global_operands();
     clear_global_operator();
}
//----------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------
void set_global_operand1(int32_t value){
 addToOpperand(&_global_opperand1,value);
}
//----------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------
void set_global_operand2( int32_t value){
addToOpperand(&_global_opperand2,value);
}
//----------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------
void set_global_operator(char value){
 update_operator(&_global_operator,value);
}//----------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------
//update the operator
void update_operator(char *operator, char value){
*operator = value;
}
//----------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------
//updates the value of the operand
void addToOpperand(int32_t *opperand, int value)
{
    int32_t result = *opperand * 10 + value;
    if (((*opperand > 0) && (result < *opperand)) || result > INT32_MAX)
    {
        return; // dont do anything because we are at the max number so just ignore the input
    }
    *opperand = result; // set the value
}
//----------------------