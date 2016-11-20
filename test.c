
#include "stdio.h"

#include "ansi.h"
#include "box.h"

box_t main_window;

void main()
{
    main_window.x1 = 0;
    main_window.y1 = 0;
    main_window.x2 = 0;
    main_window.y2 = 0;
    main_window.fgcolor = WHITE;
    main_window.bgcolor = BLUE;

    box_draw(&main_window);
}
