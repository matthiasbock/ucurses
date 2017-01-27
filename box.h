/**
 * TUI box/window
 *
 * Author: Matthias Bock
 * License: GNU GPL v3
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <stdint.h>

#include "ucurses_config.h"
#include "io.h"

typedef struct
{
    uint8_t fgcolor;
    uint8_t bgcolor;
    uint8_t x1, y1, x2, y2;
} box_t;

void box_draw(box_t*);

#ifdef BOX_STYLE_SIMPLE
#define BOX_CORNER_LOWER_RIGHT "/"
#define BOX_CORNER_UPPER_RIGHT "\\"
#define BOX_CORNER_UPPER_LEFT  "/"
#define BOX_CORNER_LOWER_LEFT  "\\"
#define BOX_EDGE_HORIZONTAL    "-"
#define BOX_EDGE_VERTICAL      "|"
#define BOX_SPACE              " "
#endif

#ifdef BOX_STYLE_ANSI
#define BOX_CORNER_LOWER_RIGHT "\x6a"
#define BOX_CORNER_UPPER_RIGHT "\x6b"
#define BOX_CORNER_UPPER_LEFT  "\x6c"
#define BOX_CORNER_LOWER_LEFT  "\x6d"
#define BOX_EDGE_HORIZONTAL    "\x71"
#define BOX_EDGE_VERTICAL      "\x78"
#define BOX_SPACE              "\x20"
#endif

#ifdef BOX_STYLE_UTF8
#define BOX_CORNER_LOWER_RIGHT "\x25\x18"
#define BOX_CORNER_UPPER_RIGHT "\x25\x10"
#define BOX_CORNER_UPPER_LEFT  "\x25\x0C"
#define BOX_CORNER_LOWER_LEFT  "\x25\x14"
#define BOX_EDGE_HORIZONTAL    "\x25\x02"
#define BOX_EDGE_VERTICAL      "\x25\x00"
#define BOX_SPACE              "\x00\x20"
#endif

#endif
