
#include <stdio.h>
#include <stdbool.h>

#include "ansi.h"
#include "io.h"
#include "box.h"
#include "label.h"
#include "slider.h"
#include "checkbox.h"

box_t   main_window;
label_t title;

slider_t   slider;
checkbox_t checkbox;

void refresh()
{
    box_draw(&main_window);
    label_draw(&title);
    slider_draw(&slider);
    checkbox_draw(&checkbox);
}

int main()
{
    main_window.x1 = 1;
    main_window.y1 = 1;
    main_window.x2 = 80;
    main_window.y2 = 25;
    main_window.color = ANSI_FG_WHITE ANSI_BG_BLUE;

    title.x = 10;
    title.y = main_window.y1 + 2;
    title.text = "ucurses test program";
    title.color = ANSI_FG_CYAN ANSI_BG_BLUE;

    slider.x1 = 10;
    slider.x2 = 20;
    slider.y  = title.y + 2;
    slider.value_min = 1;
    slider.value_max = 10;
    slider.value = 5;
    slider.color = ANSI_FG_BLUE ANSI_BG_WHITE;

    checkbox.x = 10;
    checkbox.y = slider.y + 2;
    checkbox.checked = true;
    checkbox.color = ANSI_FG_WHITE ANSI_BG_BLUE;

    refresh();

    // begin terminal below window
    ansi_gotoxy(1, main_window.y2+1);

    // reset colors
    printf(ANSI_RESET);

    return 0;
}
