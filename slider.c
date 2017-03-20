
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

bool slider_decrement(slider_t* slider)
{
    // decrease value
    if (slider->value == slider->value_min)
        return false;
    slider->value -= slider->stepsize;
    if (slider->value < slider->value_min)
        slider->value = slider->value_min;

    // redraw element
    slider_draw(slider);
    return true;
}

bool slider_increment(slider_t* slider)
{
    // increase value
    if (slider->value == slider->value_max)
        return false;
    slider->value += slider->stepsize;
    if (slider->value > slider->value_max)
        slider->value = slider->value_max;

    // redraw element
    slider_draw(slider);
    return true;
}

void slider_select(slider_t* slider)
{
    slider->selected = true;
    slider_draw(slider);
}

void slider_deselect(slider_t* slider)
{
    slider->selected = false;
    slider_draw(slider);
}
