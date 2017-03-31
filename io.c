
#include "io.h"

/*
 * Methods, which are only working
 * with an ANSI-compatible terminal
 */
#ifdef TERMINAL_TYPE_ANSI

void ansi_setcolor(char* color)
{
    #ifdef USE_COLORS
    prints(color);
    #endif
}

void ansi_gotoxy(uint8_t x, uint8_t y)
{
    prints(ANSI_ESC "[");
    char s[5];
    int2str(y, s);
    prints(s);
    printc(';');
    int2str(x, s);
    prints(s);
    printc('H');
}

#endif // TERMINAL_TYPE_ANSI


#ifdef EMBEDDED
/*
 * use UART console on microcontroller
 */

void printc(char c)
{
    uart_send_char(c);
}

void prints(char* s)
{
    uint8_t p = 0;
    while (s[p] != 0 && p < 255)
    {
        printc(s[p++]);
    }
}

#else
/*
 * use standard out on PC
 */

void printc(char c)
{
    printf("%c", c);
}

void prints(char* s)
{
    printf(s);
}

#endif
