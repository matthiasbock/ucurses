/**
 * TUI button
 *
 * Author: Matthias Bock
 * License: GNU GPL v3
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "ucurses_config.h"
#include "io.h"

typedef struct
{
    char*   color;
    uint8_t x1, x2;
    uint8_t y;
    char*   label;
} button_t;

void button_draw(button_t*);

#endif
