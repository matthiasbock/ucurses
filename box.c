
#include "box.h"

void box_draw(
        box_t* box
        )
{
    setfgcolor(box->fgcolor);
    setbgcolor(box->bgcolor);

    gotoxy(box->x1, box->y1);
    prints(ANSI_BEGIN_GRAPHICAL);

    prints(BOX_CORNER_UPPER_LEFT);
    for (uint8_t x=box->x1+1; x<box->x2; x++)
    {
        prints(BOX_EDGE_HORIZONTAL);
    }
    prints(BOX_CORNER_UPPER_RIGHT "\n");

    for (uint8_t y=box->y1+1; y<box->y2; y++)
    {
        gotoxy(box->x1, y);
        prints(BOX_EDGE_VERTICAL);

        for (uint8_t x=box->x1+1; x<box->x2; x++)
        {
            prints(BOX_SPACE);
        }

        gotoxy(box->x2, y);
        prints(BOX_EDGE_VERTICAL "\n");
    }

    gotoxy(box->x1, box->y2);
    prints(BOX_CORNER_LOWER_LEFT);
    for (uint8_t x=box->x1+1; x<box->x2; x++)
    {
        prints(BOX_EDGE_HORIZONTAL);
    }
    prints(BOX_CORNER_LOWER_RIGHT "\n");

    prints(ANSI_END_GRAPHICAL);
}
