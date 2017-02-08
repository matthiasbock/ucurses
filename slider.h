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
    char*    color;
    float    value_min;
    float    value_max;
    float    value;
    uint32_t x1, x2, y;
} slider_t;

void slider_draw(slider_t*);

#define SLIDER_ARROW_LEFT   "<"
#define SLIDER_ARROW_RIGHT  ">"
#define SLIDER_BLOCK        "a"
#define SLIDER_MARKER       " "

#endif
