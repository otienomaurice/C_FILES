

#include "stdint.h"
#include "stdbool.h"
#ifndef BUTTON_H
#define BUTTON_H

#define BUTTON_PRESSED_MS 1000
//defines every button as a struct
//the struct member c is the character to be displayed on the screen
//structure members x,y,w,h are the top left coordiantes, the width and the
//height of the buttons respectively
//the member pressed is a flag for the status of the button
//it tells whether the button has been pressed or not
struct Button
{
    bool pressed;
    bool cooldown;
    uint32_t x, y, w, h;
    uint32_t time;
    char c;
};
//creates a button with the properties given in the parameters 
struct Button createButton(int16_t x, int16_t y, int16_t w, int16_t h, char c);
//gets the status of the button
bool getPressed(struct Button *button);
//ticks the button
void tick_button(struct Button *button, int16_t x, int16_t y, bool isTouched);

#endif