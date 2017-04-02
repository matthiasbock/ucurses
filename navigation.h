/**
 * Library to handle navigation through TUI elements
 * e.g with arrow keys
 */

#ifndef UCURSES_NAVIGATION_H
#define UCURSES_NAVIGATION_H

#include <stdbool.h>
#include <stdint.h>

// include select/deselect functions from TUI elements
#include "slider.h"
#include "checkbox.h"
#include "button.h"

// uses special key definitions from ushell.h
#include <ushell.h>

// possible types for selectable elements
typedef enum
{
    TYPE_CHECKBOX,
    TYPE_EDIT,
    TYPE_SLIDER,
    TYPE_BUTTON,
} element_type_t;

// a struct to represent a selectable element within a TUI
typedef struct
{
    element_type_t type;
    void* element;
} selectable_t;

// a struct to hold all information relevant for tui navigation handling
typedef struct
{
    selectable_t* selectables;
    uint8_t selectables_count;
    uint8_t selected;
} navigation_t;

/**
 * Keystroke handler for arrow keys,
 * which allow the user to browse through selectable elements in a TUI
 *
 * returns true, when the key was handled
 */
bool navigation_keystroke_handler(navigation_t*, uint32_t);

#endif // UCURSES_NAVIGATION_H

