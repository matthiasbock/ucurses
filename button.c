
#include "button.h"

void button_draw(
    button_t* button
    )
{
    ansi_setcolor(button->color);

    ansi_gotoxy(button->x, button->y);

    prints(" < ");
    prints(button->label);
    prints(" > ");
}
