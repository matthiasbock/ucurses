
#include "stdio.h"

#include "ansi.h"
#include "box.h"

box_t main_window;

void main()
{
    main_window.x1 = 1;
    main_window.y1 = 1;
    main_window.x2 = 80;
    main_window.y2 = 25;
    main_window.fgcolor = WHITE;
    main_window.bgcolor = BLUE;

    box_draw(&main_window);

    // reset colors
    printf(ANSI_RESET);
    printf("\n");
}
