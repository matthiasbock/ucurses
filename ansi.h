/**
 * ANSI escape codes
 *
 * https://en.wikipedia.org/wiki/ANSI_escape_code
 * http://bluesock.org/~willg/dev/ansi.html
 * http://ascii-table.com/ansi-escape-sequences-vt-100.php
 */

#ifndef ANSI_H
#define ANSI_H

#define ESC             "\x1b"

#define WHITE               47
#define YELLOW              33
#define BLUE                34

#define ANSI_RESET      "\x1b[0m"

#define ANSI_FG_RED     "\x1b[31m"
#define ANSI_FG_GREEN   "\x1b[32m"
#define ANSI_FG_YELLOW  "\x1b[33m"
#define ANSI_FG_BLUE    "\x1b[34m"
#define ANSI_FG_MAGENTA "\x1b[35m"
#define ANSI_FG_CYAN    "\x1b[36m"
#define ANSI_FG_WHITE   "\x1b[37m"

#define ANSI_BG_BLACK   "\x1b[40m"
#define ANSI_BG_RED     "\x1b[41m"
#define ANSI_BG_GREEN   "\x1b[42m"
#define ANSI_BG_YELLOW  "\x1b[43m"
#define ANSI_BG_BLUE    "\x1b[44m"
#define ANSI_BG_MAGENTA "\x1b[45m"
#define ANSI_BG_CYAN    "\x1b[46m"
#define ANSI_BG_WHITE   "\x1b[47m"

#define ANSI_BEGIN_GRAPHICAL "\e(0"
#define ANSI_END_GRAPHICAL   "\e(B"

#endif
