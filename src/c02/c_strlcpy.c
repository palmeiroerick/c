#include "libc.h"
#include <stdint.h>

void putstrmem(char *str) {
    char digits[16] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };

    int size = sizeof(str);

    char address_str[size + 2];
    address_str[0] = '0';
    address_str[1] = 'x';

    uintptr_t address, high_nibble, low_nibble;

    address = (uintptr_t)str;

    high_nibble = address / 16;
    low_nibble = address % 16;
    address_str[2] = digits[low_nibble];

    int i = 1;
    while (i < size * 2) {
        low_nibble = high_nibble % 16;
        high_nibble = high_nibble / 16;
        address_str[i+2] = digits[low_nibble];
        i++;
    }

    c_putstr(address_str);
    c_putstr(" -> ");
    c_putstr(str);
    c_putstr("\n");
}

size_t c_strlcpy(char *dest, const char *src, size_t dsize) {
    size_t i = 0;

    if (dsize != 0) {
        while (src[i] && i < dsize - 1) {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    while (src[i]) {
        i++;
    }

    return i;
}

int main(void) {
    char *hello = "Hello, World!";
    putstrmem(hello);
    char copy[10];

    c_strlcpy(copy, hello, 10);
    putstrmem(copy);
    return 0;
}