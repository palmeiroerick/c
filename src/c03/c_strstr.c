#include "libc.h"

// Naive approach.
// I am not particuarly interested in go deeper in this one.

char *c_strstr(char *str, char *substr) {
    if (*substr == '\0') return str;

    while (*str) {
        char *ptr = str;
        char *subptr = substr;
        while (*subptr && *ptr == *subptr) { ptr++; subptr++; }
        if (*subptr == '\0') return str;
        str++;
    }

    return NULL;
}

int main(void) {
    char *hello = "Hello, World!";
    char *world = c_strstr(hello, "World");
    // char *world = hello + 7;
    // I don't know how to test it.
    c_putstr(world); // That's just for the compiler
    return 0;
}