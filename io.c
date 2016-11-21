
#include "io.h"

void setfgcolor(uint8_t color)
{
    switch(color)
    {
        case YELLOW:
            printf(ANSI_FG_YELLOW);
            break;

        case BLUE:
            printf(ANSI_FG_BLUE);
            break;

        case WHITE:
            printf(ANSI_FG_WHITE);
            break;

        default:
            break;
    }
}

void setbgcolor(uint8_t color)
{
    switch(color)
    {
        case YELLOW:
            printf(ANSI_BG_YELLOW);
            break;

        case BLUE:
            printf(ANSI_BG_BLUE);
            break;

        case WHITE:
            printf(ANSI_BG_WHITE);
            break;

        default:
            break;
    }
}

void gotoxy(uint8_t x, uint8_t y)
{
    printf(ESC "[%d;%dH", y, x);
}

void printc(char c)
{
    printf(&c);
}

void prints(char* s)
{
    printf(s);
}
