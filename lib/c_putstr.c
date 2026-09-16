#include "libc.h"

void c_putstr(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    write(1, str, i);
}