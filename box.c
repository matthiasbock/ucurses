
#include "box.h"

void box_draw(
        box_t* box
        )
{
    setfgcolor(box->fgcolor);
    setbgcolor(box->bgcolor);
    gotoxy(box->x1, box->y1);
    printf(ANSI_BEGIN_GRAPHICAL "\x6a" ANSI_END_GRAPHICAL ANSI_RESET "\n");
}
