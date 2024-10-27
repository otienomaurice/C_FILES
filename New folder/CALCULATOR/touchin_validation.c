
#include "stdbool.h"
#include "button.h"
#include "TouchScreen.h"
#include "global.h"
#include "button.h"
#include "global.h"
// int32_t _global_opperand1; 
// int32_t _global_opperand2 ; 
//  char  _global_operator;
//get the first operand
char button_info_fill(){
     //set the button info, find waht button has been pressed
    get_touch_info();
         //check for every button, if pressed add the value returned to operand
        for (int i = 0; i < btnCnt; i++)
        {    //if the button is pressed, check if it is a digit, operator or command
            if (buttons[i].pressed)
            {
                
                switch(buttons[i].c){
                     case 'c':
                     clear_pressed = true;
                     break;
                
                //if button is an equals
                     case '=': 
                         equal_pressed = true;
                         //set result to value of calculation
                         //display the result
                     break;
                //if button is an operator, update the operator
                     case '+':
                     set_global_operator('+');
                     operator_pressed = true;
                     break;
                     case '-':
                     set_global_operator('-');
                     operator_pressed = true;
                     break;
                     case 'x':
                     set_global_operator('x');
                     operator_pressed = true;
                     break;
                     case '/':
                     set_global_operator('/');
                     operator_pressed = true;
                     break;
                //if button is an operand
                     case '0':
                     if( input_operand2)
                     set_global_operand2(0);
                     else
                     set_global_operand1(0);
                     operand_pressed = true;
                     break;
                      case '1':
                     if( input_operand2)
                     set_global_operand2(2);
                     else
                     set_global_operand1(2);
                     operand_pressed = true;
                     break;
                      case '2':
                     if( input_operand2)
                     set_global_operand2(2);
                     else
                     set_global_operand1(2);
                     operand_pressed = true;
                     break;
                      case '3':
                     if( input_operand2)
                     set_global_operand2(3);
                     else
                     set_global_operand1(3);
                     operand_pressed = true;
                     break;
                      case '4':
                     if( input_operand2)
                     set_global_operand2(4);
                     else
                     set_global_operand1(4);
                     operand_pressed = true;
                     break;
                      case '5':
                     if( input_operand2)
                     set_global_operand2(5);
                     else
                     set_global_operand1(5);
                     operand_pressed = true;
                     break;
                      case '6':
                     if( input_operand2)
                     set_global_operand2(6);
                     else
                     set_global_operand1(6);
                     operand_pressed = true;
                     break;
                      case '7':
                     if( input_operand2)
                     set_global_operand2(7);
                     else
                     set_global_operand1(7);
                     operand_pressed = true;
                     break;
                      case '8':
                     if( input_operand2)
                     set_global_operand2(8);
                     else
                     set_global_operand1(8);
                     operand_pressed = true;
                     break;
                      case '9':
                     if( input_operand2)
                     set_global_operand2(9);
                     else
                     set_global_operand1(9);
                     operand_pressed = true;
                     break;
                    default:
                    ;
                     break;
                }
            }
            return buttons[i].c;
        }
        return;
        
}
//-----------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
void get_touch_info(){
        //assign the x and y coordinates to  x and y when touched and return true
        uint16_t x, y;
        bool isTouched = get_ts_lcd(&x, &y);
          for (int i = 0; i < btnCnt; i++)
        {
                tick_button(&buttons[i], x, y, isTouched);
        }
        
}
//------------------------------------------------------------------------------------------------