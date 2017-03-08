/**
 * ANSI escape codes
 *
 * https://en.wikipedia.org/wiki/ANSI_escape_code
 * http://bluesock.org/~willg/dev/ansi.html
 * http://ascii-table.com/ansi-escape-sequences-vt-100.php
 *
 * Author: Matthias Bock <mail@matthiasbock.net>
 * This file is hereby released into the public domain.
 */

#ifndef ANSI_H
#define ANSI_H

#ifndef STR
// http://stackoverflow.com/questions/5459868/c-preprocessor-concatenate-int-to-string
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#endif

#define ESC                 "\x1b"

#define ANSI_CLEAR_SCREEN   ESC "[2J"

#define ANSI_RESET          ESC "[0m"

#define ANSI_FG_RED         ESC "[31m"
#define ANSI_FG_GREEN       ESC "[32m"
#define ANSI_FG_YELLOW      ESC "[33m"
#define ANSI_FG_BLUE        ESC "[34m"
#define ANSI_FG_MAGENTA     ESC "[35m"
#define ANSI_FG_CYAN        ESC "[36m"
#define ANSI_FG_WHITE       ESC "[37m"

#define ANSI_BG_BLACK       ESC "[40m"
#define ANSI_BG_RED         ESC "[41m"
#define ANSI_BG_GREEN       ESC "[42m"
#define ANSI_BG_YELLOW      ESC "[43m"
#define ANSI_BG_BLUE        ESC "[44m"
#define ANSI_BG_MAGENTA     ESC "[45m"
#define ANSI_BG_CYAN        ESC "[46m"
#define ANSI_BG_WHITE       ESC "[47m"

#define ANSI_BEGIN_GRAPHICAL "\e(0"
#define ANSI_END_GRAPHICAL   "\e(B"

#define ANSI_MOVE_CURSOR_TO(x, y)   ESC "[" STR(y) ";" STR(x) "H"

#endif
