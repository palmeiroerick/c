#include "libc.h"

// i feel that a lot of historical stuff is being hidden
// with this variants of different functions. it would be
// interesting to explore the fact that strcat assumes the
// *dest is long enought to hold *src and why strncat exits

char *c_strncat(char *dest, char *src, size_t size) {
    char *ptr = dest;
    while (*dest) { dest++; }
    size_t i = 0;
    while (*src && i < size) { *dest = *src; dest++; src++; i++; }
    *dest = '\0';
    return ptr;
}

int main(void) {
    char str[14] = "";
    char *hello = "hello";
    char *world = ", world!";
    c_strncat(str, hello, 6);
    c_strncat(str, world, 6);
    c_putstr(str);
    return 0;
}