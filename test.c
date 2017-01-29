
#include <stdio.h>

#include "ansi.h"
#include "io.h"
#include "label.h"s
#include "box.h"
#include "slider.h"

box_t main_window;
slider_t slider;
label_t title;

void refresh()
{
    box_draw(&main_window);
    label_draw(&title);
    slider_draw(&slider);
}

int main()
{
    main_window.x1 = 1;
    main_window.y1 = 1;
    main_window.x2 = 80;
    main_window.y2 = 25;
    main_window.color = ANSI_FG_WHITE ANSI_BG_BLUE;

    title.x = 10;
    title.y = 3;
    title.text = "ucurses test program";
    title.color = ANSI_FG_CYAN ANSI_BG_BLUE;

    slider.x1 = 10;
    slider.x2 = 20;
    slider.y  = 5;
    slider.value_min = 1;
    slider.value_max = 10;
    slider.value = 5;
    slider.color = ANSI_FG_BLUE ANSI_BG_WHITE;

    refresh();

    // begin terminal below window
    ansi_gotoxy(1, main_window.y2+1);

    // reset colors
    printf(ANSI_RESET);

    return 0;
}
