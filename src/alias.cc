#pragma once
#include <stdint.h>

// i will always love the rust typenames
typedef int8_t  s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;



// colrs
#define ESC "\x1b["

#define RESET ESC "0m"

#define BOLD ESC "1m"
#define NO_BOLD ESC "22m"

#define ITALIC ESC "3m"
#define NO_ITALIC ESC "23m"

#define BLACK ESC "30m"
#define RED ESC "31m"
#define GREEN ESC "32m"
#define YELLOW ESC "33m"
#define BLUE ESC "34m"
#define MAGENTA ESC "35m"
#define CYAN ESC "36m"
#define WHITE ESC "37m"
#define DEFAULT ESC "39m"

#define BG_BLACK ESC "40m"
#define BG_RED ESC "41m"
#define BG_GREEN ESC "42m"
#define BG_YELLOW ESC "43m"
#define BG_BLUE ESC "44m"
#define BG_MAGENTA ESC "45m"
#define BG_CYAN ESC "46m"
#define BG_WHITE ESC "47m"
#define BG_DEFAULT ESC "49m"

#define FG_256(id) ESC "38;5;" #id "m"
#define BG_256(id) ESC "48;5;" #id "m"

#define FG_TC(r, g, b) ESC "38;2;" #r ";" #g ";" #b "m"
#define BG_TC(r, g, b) ESC "48;2;" #r ";" #g ";" #b "m"

#define NEWLINE "\n"