
#include "box.h"

void box_draw(
        box_t* box
        )
{
    ansi_setcolor(box->color);

    ansi_gotoxy(box->x1, box->y1);
    prints(ANSI_BEGIN_GRAPHICAL);

    prints(BOX_CORNER_UPPER_LEFT);
    for (uint8_t x=box->x1+1; x<box->x2; x++)
    {
        prints(BOX_EDGE_HORIZONTAL);
    }
    prints(BOX_CORNER_UPPER_RIGHT);

    for (uint8_t y=box->y1+1; y<box->y2; y++)
    {
        ansi_gotoxy(box->x1, y);
        prints(BOX_EDGE_VERTICAL);

        for (uint8_t x=box->x1+1; x<box->x2; x++)
        {
            prints(BOX_SPACE);
        }

        //ansi_gotoxy(box->x2, y);
        prints(BOX_EDGE_VERTICAL);
    }

    ansi_gotoxy(box->x1, box->y2);
    prints(BOX_CORNER_LOWER_LEFT);
    for (uint8_t x=box->x1+1; x<box->x2; x++)
    {
        prints(BOX_EDGE_HORIZONTAL);
    }
    prints(BOX_CORNER_LOWER_RIGHT);

    prints(ANSI_END_GRAPHICAL);
}
