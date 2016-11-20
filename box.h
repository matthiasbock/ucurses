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

#endif
