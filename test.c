
#include <stdio.h>

#include "ansi.h"
#include "io.h"
#include "box.h"
#include "slider.h"

box_t main_window;
slider_t slider;

int main()
{
    printf(ANSI_BEGIN_GRAPHICAL);

    main_window.x1 = 1;
    main_window.y1 = 1;
    main_window.x2 = 80;
    main_window.y2 = 25;
    main_window.fgcolor = WHITE;
    main_window.bgcolor = BLUE;

    box_draw(&main_window);

    slider.x1 = 10;
    slider.x2 = 20;
    slider.y  = 5;
    slider.value_min = 1;
    slider.value_max = 10;
    slider.value = 5;
    slider.fgcolor = WHITE;
    slider.bgcolor = BLUE;

    slider_draw(&slider);

    // begin terminal below window
    ansi_gotoxy(1, main_window.y2+1);

    // reset colors
    printf(ANSI_END_GRAPHICAL);
    printf(ANSI_RESET);

    return 0;
}
