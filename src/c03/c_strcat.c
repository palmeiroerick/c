#include "libc.h"

// This will be inneficient if used multiples times
// sequentially, because the function is constantely
// recalculating the *dest lenght.

char *c_strcat(char *dest, char *src) {
    char *ptr = dest;
    while (*dest) { dest++; }
    while (*src) { *dest = *src; dest++; src++; }
    *dest = '\0';
    return ptr;
}

int main(void) {
    char str[14] = "";
    char *hello = "Hello";
    char *world = ", World!";
    c_strcat(str, hello);
    c_strcat(str, world);
    c_putstr(str);
}