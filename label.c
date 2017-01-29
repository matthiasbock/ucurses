
#include "label.h"

void label_draw(
    label_t* label
    )
{
	ansi_setcolor(label->color);

    ansi_gotoxy(label->x, label->y);

    prints(label->text);
}
