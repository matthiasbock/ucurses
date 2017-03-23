
#include "slider.h"

void slider_draw(
    slider_t* slider
    )
{
    if (slider->selected)
        ansi_setcolor(slider->color_selected);
    else
        ansi_setcolor(slider->color);

    ansi_gotoxy(slider->x1, slider->y);
    prints(ANSI_BEGIN_GRAPHICAL);
    prints(SLIDER_ARROW_LEFT);

    uint8_t x_marker = (uint8_t) (slider->x1 + 1 + ((slider->value - slider->value_min + 1) / (float) (slider->value_max - slider->value_min + 1) * (slider->x2 - 1 - slider->x1 - 1)));

    for (uint8_t x=slider->x1+1; x<slider->x2; x++)
    {
        if (x != x_marker)
            prints(SLIDER_BLOCK);
        else
            prints(SLIDER_MARKER);
    }

    ansi_gotoxy(slider->x2, slider->y);
    prints(SLIDER_ARROW_RIGHT);

    prints(ANSI_END_GRAPHICAL);
}

void slider_set_value(slider_t* slider, float value)
{
    slider->value = value;
    if (slider->value < slider->value_min)
        slider->value = slider->value_min;
    if (slider->value > slider->value_max)
        slider->value = slider->value_max;
    slider_draw(slider);
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
