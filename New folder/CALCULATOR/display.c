
#include "ts_lcd.h"
#include "button.h"
#include "global.h"
//instantiate the global display to cursor
// char _global_display[50] = "|";
//--------------------------------------------------------------------------------------
void display_bottons(){
//render all buttons on the screen
        for (int i = 0; i < btnCnt; i++)
        {
            render_button(&buttons[i]);
        }
}
//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
void display_text(){
//display text on the screen
        render_text(_global_display);   
    }
 //---------------------------------------------------------------------------------------


