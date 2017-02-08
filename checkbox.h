/**
 * TUI checkbox
 *
 * Visualizes a two-option box
 *
 * Author: Matthias Bock
 * License: GNU GPL v3
 */

#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <stdint.h>
#include <stdbool.h>

#include "ucurses_config.h"
#include "io.h"

typedef struct
{
    char*   color;
    uint8_t x, y;
    bool    checked;
} checkbox_t;

void checkbox_draw(checkbox_t*);

#endif
