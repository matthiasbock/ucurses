/**
 * Test program for various TUI elements
 *
 * Author: Matthias Bock <mail@matthiasbock.net>
 * License: GNU GPLv3
 *
 * You are required to make all sourcecode public,
 * which uses parts of this file. Otherwise you must
 * contact the author and buy a license.
 */

#include <stdio.h>
#include <stdbool.h>

#include "ansi.h"
#include "io.h"
#include "box.h"
#include "label.h"
#include "slider.h"
#include "checkbox.h"
#include "button.h"

/**
 * A simple test window with:
 *  labels,
 *  a slider and
 *  a checkbox
 */
struct
{

    box_t      window;
    label_t    title;
    slider_t   slider;
    checkbox_t checkbox;
    button_t   button;

} test =
{
    .window =
        {
            .x1 = 1,
            .y1 = 1,
            .x2 = 80,
            .y2 = 25,
            .color = ANSI_FG_WHITE ANSI_BG_BLUE,
        },
    .title =
        {
            .x = 10,
            .y = 3,
            .text = "ucurses test program",
            .color = ANSI_FG_CYAN ANSI_BG_BLUE,
        },
    .slider =
        {
            .x1 = 10,
            .x2 = 20,
            .y  = 5,
            .value_min = 1,
            .value_max = 10,
            .value = 5,
            .color = ANSI_FG_BLUE ANSI_BG_WHITE,
        },
    .checkbox =
        {
            .x = 10,
            .y = 7,
            .checked = true,
            .color = ANSI_FG_WHITE ANSI_BG_BLUE,
        },
    .button =
        {
            .x1 = 10,
            .x2 = 20,
            .y = 9,
            .label = "Test",
            .color = ANSI_FG_BLUE ANSI_BG_WHITE,
        },
};

/**
 * Draw all elements of this TUI
 */
void tui_draw()
{
    box_draw(&test.window);
    label_draw(&test.title);
    slider_draw(&test.slider);
    checkbox_draw(&test.checkbox);
    button_draw(&test.button);
}

/**
 * Main program
 */
int main()
{
    tui_draw();

    // begin terminal below window
    ansi_gotoxy(1, 26);

    // reset colors
    printf(ANSI_RESET);

    return 0;
}
