/**
 * Text label
 *
 * Author: Matthias Bock
 * License: GNU GPL v3
 */

#ifndef LABEL_H
#define LABEL_H

#include <stdint.h>

#include "ucurses_config.h"
#include "io.h"

typedef struct
{
    char*   color;
    uint8_t x;
    uint8_t y;
    char*   text;
} label_t;

#endif
