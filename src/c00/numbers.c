#include "libc.h"

void numbers(void) {
    char c = '0';

    while (c <= '9') {
        c_putchar(c);
        c++;
    }
}

int main(void) {
    numbers();
    return 0;
}