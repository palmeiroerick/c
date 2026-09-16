#include "libc.h"

int c_strlen(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    return i;
}

int main(void) {
    c_putnbr(c_strlen("Hello, World!"));
    return 0;
}