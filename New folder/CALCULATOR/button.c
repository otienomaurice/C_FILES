
#include "button.h"
#include "stdint.h"
#include "stdbool.h"
#include "global.h"

struct Button createButton(int16_t x, int16_t y, int16_t w, int16_t h, char c)
{
    struct Button button;
    button.pressed = false;
    button.cooldown = false;
    button.time = 0;
    button.x = x;
    button.y = y;
    button.w = w;
    button.h = h;
    button.c = c;

    return button;
}

bool getPressed(struct Button *button)
{
    return button->pressed;
}
char getButtonChar(struct Button *button){
    return button->c;
}
bool is_in_area(struct Button *button, int16_t x, int16_t y)
{
    return (x > button->x && x < button->x + button->w && y > button->y && y < button->y + button->h);
}

void tick_button(struct Button *button, int16_t x, int16_t y, bool isTouched)
{

    if (button->pressed)
    {
        button->pressed = false;
        button->cooldown = true;
        return;
    }

    if (button->cooldown && (!(isTouched && is_in_area(button, x, y))))
    {
        button->cooldown = false;
        return;
    }

    if (isTouched && is_in_area(button, x, y))
    {
        button->pressed = true;
        return;
    }
}
//------------------------------------------------------------------------------------------
//initialize each button
void initButton(struct Button b)
{
    buttons[btnCnt] = b;
    btnCnt++;
}
//---------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------
//creates all buttons
void create_All_Buttons(){
    initButton(createButton(0, 40, 83, 50, '7'));
    initButton(createButton(83, 40, 83, 50, '8'));
    initButton(createButton(83 * 2, 40, 83, 50, '9'));
    initButton(createButton(0, 50 * 1 + 40, 83, 50, '4'));
    initButton(createButton(83, 50 * 1 + 40, 83, 50, '5'));
    initButton(createButton(83 * 2, 50 * 1 + 40, 83, 50, '6'));

    initButton(createButton(0, 50 * 2 + 40, 83, 50, '1'));
    initButton(createButton(83, 50 * 2 + 40, 83, 50, '2'));
    initButton(createButton(83 * 2, 50 * 2 + 40, 83, 50, '3'));
    initButton(createButton(0, 50 * 3 + 40, 83, 50, '0'));
    // the next set of buttons
    initButton(createButton(83 * 3, 50 * 0 + 40, 83, 50, '+'));
    initButton(createButton(83 * 3, 50 * 1 + 40, 83, 50, '-'));
    initButton(createButton(83 * 3, 50 * 2 + 40, 83, 50, '/'));
    initButton(createButton(83 * 3, 50 * 3 + 40, 83, 50, 'x'));
    initButton(createButton(83 * 2, 50 * 3 + 40, 83, 50, 'C'));
    initButton(createButton(83 * 1, 50 * 3 + 40, 83, 50, '='));
}
//---------------------------------------------------------------------------------------
