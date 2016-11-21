/**
 * TUI window
 * with double-lined boundaries
 *
 * Author: Matthias Bock
 * License: GNU GPL v3
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <stdint.h>

#include "io.h"

typedef struct
{
    uint8_t fgcolor;
    uint8_t bgcolor;
    uint8_t x1, y1, x2, y2;
} box_t;

void box_draw(box_t*);

#define BOX_CORNER_LOWER_RIGHT "\x6a"
#define BOX_CORNER_UPPER_RIGHT "\x6b"
#define BOX_CORNER_UPPER_LEFT  "\x6c"
#define BOX_CORNER_LOWER_LEFT  "\x6d"
#define BOX_EDGE_HORIZONTAL    "\x71"
#define BOX_EDGE_VERTICAL      "\x78"

#endif
