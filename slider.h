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

// uses special key definitions from ushell.h
#include <ushell.h>

#ifdef SLIDER_STYLE_SIMPLE
#define SLIDER_ARROW_LEFT   "["
#define SLIDER_ARROW_RIGHT  "]"
#define SLIDER_BLOCK        "-"
#define SLIDER_MARKER       "#"
#endif

#ifdef SLIDER_STYLE_ANSI
#define SLIDER_ARROW_LEFT   "<"
#define SLIDER_ARROW_RIGHT  ">"
#define SLIDER_BLOCK        "a"
#define SLIDER_MARKER       " "
#endif

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

    uint8_t  x_marker;
    uint8_t  x_marker_previously;
} slider_t;

/**
 * Draw slider to terminal
 */
void slider_draw(slider_t*);

/**
 * Re-calculates the X marker position from the current value
 */
void slider_calculate_marker_position(slider_t*);

/**
 * Re-calculates marker position
 * and -if necessary- re-draws slider
 */
void slider_refresh(slider_t*);

/**
 * Mark slider selected and redraw
 */
void slider_select(slider_t*);

/**
 * Set slider to new value and redraw
 */
void slider_set_value(slider_t*, float);

/**
 * Mark slider unselected and redraw
 */
void slider_deselect(slider_t*);

/**
 * Decrease slider value by stepsize and redraw
 */
void slider_decrement(slider_t*);

/**
 * Increase slider value by stepsize and redraw
 */
void slider_increment(slider_t*);

/**
 * Handle arrow keys: modify slider value and redraw
 * return true, if key was handled
 */
bool slider_keystroke_handler(slider_t* slider, uint32_t key);

#endif
