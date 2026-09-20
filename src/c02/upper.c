#include "libc.h"

char *upper(char *str) {
    int i = 0;

    while (str[i]) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 'a' - 'A';
        }
        i++;
    }

    return str;
}

int main(void) {
    char str[] = "Hello, World!";
    c_putstr(upper(str));
    return 0;
}