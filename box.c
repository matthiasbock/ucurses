
#include "box.h"

void box_draw(
        box_t* box
        )
{
    setfgcolor(box->fgcolor);
    setbgcolor(box->bgcolor);

    gotoxy(box->x1, box->y1);
    printf(ANSI_BEGIN_GRAPHICAL);

    printf(BOX_CORNER_UPPER_LEFT);
    for (uint8_t x=box->x1+1; x<box->x2; x++)
    {
        printf(BOX_EDGE_HORIZONTAL);
    }
    printf(BOX_CORNER_UPPER_RIGHT);

    for (uint8_t y=box->y1+1; y<box->y2; y++)
    {
        gotoxy(box->x1, y);
        printf(BOX_EDGE_VERTICAL);

        for (uint8_t x=box->x1+1; x<box->x2; x++)
        {
            printf(" ");
        }

        gotoxy(box->x2, y);
        printf(BOX_EDGE_VERTICAL);
    }

    gotoxy(box->x1, box->y2);
    printf(BOX_CORNER_LOWER_LEFT);
    for (uint8_t x=box->x1+1; x<box->x2; x++)
    {
        printf(BOX_EDGE_HORIZONTAL);
    }
    printf(BOX_CORNER_LOWER_RIGHT);

    printf(ANSI_END_GRAPHICAL);
}
