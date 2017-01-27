
#include "ucurses_config.h"
#include "io.h"

/*
 * Methods, which are only working
 * with an ANSI-compatible terminal
 */
#ifdef TERMINAL_TYPE_ANSI

void ansi_setfgcolor(uint8_t color)
{
    switch(color)
    {
        case YELLOW:
            prints(ANSI_FG_YELLOW);
            break;

        case BLUE:
            prints(ANSI_FG_BLUE);
            break;

        case WHITE:
            prints(ANSI_FG_WHITE);
            break;

        default:
            break;
    }
}

void ansi_setbgcolor(uint8_t color)
{
    switch(color)
    {
        case YELLOW:
            prints(ANSI_BG_YELLOW);
            break;

        case BLUE:
            prints(ANSI_BG_BLUE);
            break;

        case WHITE:
            prints(ANSI_BG_WHITE);
            break;

        default:
            break;
    }
}

void ansi_gotoxy(uint8_t x, uint8_t y)
{
    prints(ESC "[");
    prints(inttostr(y));
    printc(';');
    prints(inttostr(x));
    printc('H');
}

#endif // TERMINAL_TYPE_ANSI

// static memory allocation
uint8_t inttostr_buffer[5];

char* inttostr(uint8_t i)
{
    const uint8_t ascii_zero = 0x30;
    uint8_t* s;
    s = inttostr_buffer;

    // hundreds
    uint8_t hundreds = i / 100;
    if (hundreds > 0)
    {
        *(s++) = ascii_zero + hundreds;
        i -= hundreds * 100;
    }

    // tens
    uint8_t tens = i / 10;
    if (tens > 0)
    {
        *(s++) = ascii_zero + tens;
        i -= tens * 10;
    }

    // 0-9
    *(s++) = ascii_zero + i;

    // string terminator
    *(s++) = 0x00;

    return inttostr_buffer;
}

#ifdef NRF51
/*
 * use UART console on microcontroller
 */

void printc(char c)
{
    uart_send_char(&c);
    //nrf_delay_ms(1); // 9600 baud
    nrf_delay_us(50);
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
    printf(&c);
}

void prints(char* s)
{
    printf(s);
}

#endif
