
#ifndef IO_H
#define IO_H

#include <stdint.h>

#include "ansi.h"

#ifndef MICROCONTROLLER
#include <stdio.h>
#endif

/**
 * Set foreground color
 */
void setfgcolor(uint8_t);

/**
 * Set background color
 */
void setbgcolor(uint8_t);

/**
 * Move cursor to position
 */
void gotoxy(uint8_t, uint8_t);

/**
 * Print character to terminal
 */
void printc(char);

/**
 * Print string to terminal
 */
void prints(char*);

#endif
