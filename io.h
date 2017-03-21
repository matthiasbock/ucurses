
#ifndef IO_H
#define IO_H

#include <stdint.h>

#include "ucurses_config.h"
#include "ansi.h"

#ifdef NRF51
// use UART console on microcontroller
#include <uart.h>
#else
// use standard out on PC
#include <stdio.h>
#endif

/**
 * @brief Set foreground and/or background color
 */
void ansi_setcolor(char*);

/**
 * @brief Move cursor to position
 */
void ansi_gotoxy(uint8_t, uint8_t);

/**
 * @brief Convert byte to three-digit-string
 */
char* inttostr(uint8_t i);

/**
 * @brief Print character to terminal
 */
void printc(char);

/**
 * @brief Print string to terminal
 */
void prints(char*);

#endif
