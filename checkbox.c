
#include "checkbox.h"

void checkbox_draw(
    checkbox_t* checkbox
    )
{
    if (checkbox->selected)
        ansi_setcolor(checkbox->color_selected);
    else
        ansi_setcolor(checkbox->color);

    ansi_gotoxy(checkbox->x, checkbox->y);

    printc('[');
    if (checkbox->checked)
        printc('X');
    else
        printc(' ');
    printc(']');
}

inline void checkbox_check(checkbox_t* c)
{
    c->checked = true;
    checkbox_draw(c);
}

inline void checkbox_uncheck(checkbox_t* c)
{
    c->checked = false;
    checkbox_draw(c);
}

inline void checkbox_toggle(checkbox_t* c)
{
    c->checked = !c->checked;
    checkbox_draw(c);
}

inline void checkbox_select(checkbox_t* c)
{
    c->selected = true;
    checkbox_draw(c);
}

inline void checkbox_deselect(checkbox_t* c)
{
    c->selected = false;
    checkbox_draw(c);
}
