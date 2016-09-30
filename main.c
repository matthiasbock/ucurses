
/**
 * A curses-based user interface for the nRF51822
 * for user interaction on the RS-232 serial port (UART0)
 */

#include <stdio.h>
#include <stdbool.h>

#define PIN_RX 5
#define PIN_TX 6

#include "sdk/uart.h"
#include "sdk/delay.h"

void main()
{
    uart_init(PIN_RX, PIN_TX, 0, 0, uart_baud_9600, false, false);

    char c = 'A';
    while (1)
    {
        uart_send_char(&c);

        delay_ms(1000);
    }
}
