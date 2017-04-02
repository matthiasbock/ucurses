
#include "navigation.h"

bool navigation_keystroke_handler(navigation_t* navigation, uint32_t key)
{
    uint8_t previously_selected = navigation->selected;

    switch (key)
    {
        case 's':
        case '2':
        case KEY_TAB:
        case KEY_DOWN:
            navigation->selected = (navigation->selected + 1) % navigation->selectables_count;
            break;

        case 'w':
        case '8':
        case KEY_SHIFT_TAB:
        case KEY_UP:
            navigation->selected = (navigation->selected + navigation->selectables_count - 1) % navigation->selectables_count;
            break;

        default:
            // key unhandled
            return false;
    }

    // leave previously selected element
    switch (navigation->selectables[previously_selected].type)
    {
        case TYPE_CHECKBOX:
            checkbox_deselect( (checkbox_t*) navigation->selectables[previously_selected].element );
            break;
        case TYPE_SLIDER:
            slider_deselect( (slider_t*) navigation->selectables[previously_selected].element );
            break;
        case TYPE_BUTTON:
            button_deselect( (button_t*) navigation->selectables[previously_selected].element );
            break;
    }

    // highlight now selected element
    switch (navigation->selectables[navigation->selected].type)
    {
        case TYPE_CHECKBOX:
            checkbox_select( (checkbox_t*) navigation->selectables[navigation->selected].element );
            break;
        case TYPE_SLIDER:
            slider_select( (slider_t*) navigation->selectables[navigation->selected].element );
            break;
        case TYPE_BUTTON:
            button_select( (button_t*) navigation->selectables[navigation->selected].element );
            break;
    }

    // key was handled
    return true;
}

