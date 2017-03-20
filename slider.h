/**
 * TUI slider
 *
 * Visualizes a value between two boundaries
 *
 * Author: Matthias Bock
 * License: GNU GPL v3
 */

#ifndef SLIDER_H
#define SLIDER_H

#include <stdbool.h>
#include <stdint.h>

#include "ucurses_config.h"
#include "io.h"

#define SLIDER_ARROW_LEFT   "<"
#define SLIDER_ARROW_RIGHT  ">"
#define SLIDER_BLOCK        "a"
#define SLIDER_MARKER       " "

typedef struct
{
    // drawing attributes
    char*    color;
    char*    color_selected;
    bool     selected;
    uint32_t x1, x2, y;

    // value
    float    value_min;
    float    value_max;
    float    value;
    float    stepsize;
} slider_t;

/**
 * Draw slider to terminal
 */
void slider_draw(slider_t*);

/**
 * Mark slider selected and redraw
 */
void slider_select(slider_t*);

/**
 * Mark slider unselected and redraw
 */
void slider_deselect(slider_t*);

/**
 * Decrease slider value by stepsize and redraw
 */
bool slider_decrement(slider_t*);

/**
 * Increase slider value by stepsize and redraw
 */
bool slider_increment(slider_t*);

#endif
