
#include "button.h"

void button_draw(
    button_t* button
    )
{
    ansi_setcolor(button->color);

    ansi_gotoxy(button->x1, button->y);
    prints(" <");

    for (uint8_t x=button->x1+2; x<=button->x2-2; x++)
        printc(' ');

    uint8_t x_label = (button->x1 + button->x2 - strlen(button->label))/2;
    ansi_gotoxy(x_label, button->y);
    prints(button->label);

    ansi_gotoxy(button->x2-1, button->y);
    prints("> ");
}
