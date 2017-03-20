
#include "button.h"

void button_draw(
    button_t* button
    )
{
    if (button->selected)
        ansi_setcolor(button->color_selected);
    else
        ansi_setcolor(button->color);

    ansi_gotoxy(button->x, button->y);

    prints(" < ");
    prints(button->label);
    prints(" > ");
}

void button_select(button_t* button)
{
    button->selected = true;
    button_draw(button);
}

void button_deselect(button_t* button)
{
    button->selected = false;
    button_draw(button);
}
