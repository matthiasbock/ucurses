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

#include <stdint.h>
#include "io.h"

typedef struct
{
    uint8_t fgcolor;
    uint8_t bgcolor;
    uint8_t value_min;
    uint8_t value_max;
    uint8_t value;
    uint8_t x1, x2, y;
} slider_t;

void slider_draw(slider_t*);

#define SLIDER_ARROW_LEFT   "<"
#define SLIDER_ARROW_RIGHT  ">"
#define SLIDER_BLOCK        "a"
#define SLIDER_MARKER       " "

#endif
