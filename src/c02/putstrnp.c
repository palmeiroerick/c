#include <unistd.h>
#include "libc.h"

int is_print(const char c) {
    return c >= ' ' && c <= '~';
}

void puthex(const char c) {
    char digits[16] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };

    char hex[4] = "\\00";

    int high_nibble, low_nibble;

    high_nibble = c / 16;
    low_nibble = c % 16;
    hex[2] = digits[low_nibble];

    int i = 1;
    while (high_nibble != 0) {
        low_nibble = high_nibble % 16;
        high_nibble = high_nibble / 16;
        hex[2 - i] = digits[low_nibble];
        i++;
    }

    c_putstr(hex);
}

void putstrnp(const char *str) {
    int i = 0;
    while (str[i]) {
        if (is_print(str[i])) {
            c_putchar(str[i]);
        } else {
            puthex(str[i]);
        }
        i++;
    }
}

int main(void) {
    putstrnp("Hello, World!\x0a");
    return 0;
}