
#include "checkbox.h"

void checkbox_draw(
    checkbox_t* checkbox
    )
{
    ansi_setcolor(checkbox->color);

    ansi_gotoxy(checkbox->x, checkbox->y);

    printc('[');
    if (checkbox->checked)
        printc('X');
    else
        printc(' ');
    printc(']');
}
