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
    uint8_t x, y;
    char*   color;
    char*   color_selected;
    bool    selected;

    bool    checked;
} checkbox_t;

void checkbox_draw(checkbox_t*);

/**
 * Mark checkbox as checked and redraw
 */
void checkbox_check(checkbox_t*);

/**
 * Mark checkbox as unchecked and redraw
 */
void checkbox_uncheck(checkbox_t*);

/**
 * Change the checked-status
 */
void checkbox_toggle(checkbox_t*);

/**
 * Mark checkbox selected and redraw
 */
void checkbox_select(checkbox_t*);

/**
 * Mark checkbox unselected and redraw
 */
void checkbox_deselect(checkbox_t*);


#endif
