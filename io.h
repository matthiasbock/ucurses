
#ifndef IO_H
#define IO_H

#include <stdint.h>

#include "ansi.h"

#ifdef NRF51
// use UART console on microcontroller
#include <uart.h>
#include <nrf_delay.h>
#else
// use standard out on PC
#include <stdio.h>
#endif

/**
 * @brief Set foreground color
 */
void setfgcolor(uint8_t);

/**
 * @brief Set background color
 */
void setbgcolor(uint8_t);

/**
 * @brief Move cursor to position
 */
void gotoxy(uint8_t, uint8_t);

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
