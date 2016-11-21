
#include "slider.h"

void slider_draw(slider_t* slider)
{
    setfgcolor(slider->bgcolor);
    setbgcolor(slider->fgcolor);

    gotoxy(slider->x1, slider->y);
    printf(ANSI_BEGIN_GRAPHICAL);
    printf(SLIDER_ARROW_LEFT);

    uint8_t x_marker = (uint8_t) (slider->x1 + 1 + ((slider->value - slider->value_min + 1) / (float) (slider->value_max - slider->value_min + 1) * (slider->x2 - 1 - slider->x1 - 1)));

    for (uint8_t x=slider->x1+1; x<slider->x2; x++)
    {
        if (x != x_marker)
            printf(SLIDER_BLOCK);
        else
            printf(SLIDER_MARKER);
    }

    gotoxy(slider->x2, slider->y);
    printf(SLIDER_ARROW_RIGHT);

    printf(ANSI_END_GRAPHICAL);
}
