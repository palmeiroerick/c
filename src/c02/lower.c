#include "libc.h"

char *lower(char *str) {
    int i = 0;

    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 'a' - 'A';
        }
        i++;
    }

    return str;
}

int main(void) {
    char str[] = "Hello, World!";
    c_putstr(lower(str));
    return 0;
}