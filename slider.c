
#include "slider.h"

void slider_draw(
    slider_t* slider
    )
{
    ansi_gotoxy(slider->x1, slider->y);

    if (slider->selected)
        ansi_setcolor(slider->color_selected);
    else
        ansi_setcolor(slider->color);

    prints(ANSI_BEGIN_GRAPHICAL SLIDER_ARROW_LEFT);
    for (uint8_t x=slider->x1+1; x<slider->x2; x++)
    {
        if (x == slider->x_marker)
            prints(SLIDER_MARKER);
        else
            prints(SLIDER_BLOCK);
    }
    prints(SLIDER_ARROW_RIGHT ANSI_END_GRAPHICAL);
}

inline void slider_calculate_marker_position(slider_t* slider)
{
    slider->x_marker_previously = slider->x_marker;
    slider->x_marker = (uint8_t) (slider->x1 + 1 + ((slider->value - slider->value_min + 1) / (float) (slider->value_max - slider->value_min + 1) * (slider->x2 - 1 - slider->x1 - 1)));
}

inline void slider_refresh(slider_t* slider)
{
    slider_calculate_marker_position(slider);
    if (slider->x_marker != slider->x_marker_previously)
        slider_draw(slider);
}

inline void slider_set_value(slider_t* slider, float value)
{
    slider->value = value;
    if (slider->value < slider->value_min)
        slider->value = slider->value_min;
    if (slider->value > slider->value_max)
        slider->value = slider->value_max;
    slider_refresh(slider);
}

inline void slider_decrement(slider_t* slider)
{
    slider_set_value(slider, slider->value - slider->stepsize);
}

inline void slider_increment(slider_t* slider)
{
    slider_set_value(slider, slider->value + slider->stepsize);
}

inline void slider_select(slider_t* slider)
{
    slider->selected = true;
    slider_draw(slider);
}

inline void slider_deselect(slider_t* slider)
{
    slider->selected = false;
    slider_draw(slider);
}

// evaluate slider-specific keys
bool slider_keystroke_handler(slider_t* slider, uint32_t key)
{
    switch (key)
    {
        case '-':
            slider_decrement(slider);
            break;

        case '+':
            slider_increment(slider);
            break;

        case KEY_PAGEUP:
        case '9': // num pad
            slider_set_value(slider, slider->value + 5*slider->stepsize);
            break;

        case KEY_PAGEDOWN:
        case '3': // num pad
            slider_set_value(slider, slider->value - 5*slider->stepsize);
            break;

        case KEY_POS1:
        case '7': // num pad
            slider_set_value(slider, slider->value_min);
            break;

        case KEY_END:
        case '1': // num pad
            slider_set_value(slider, slider->value_max);
            break;

        default:
            // key unhandled
            return false;
    }

    // key was handled
    return true;
}
