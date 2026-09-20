#include "libc.h"

int is_alpha(const char *str) {
    int i = 0;

    // 'A' <= every uppercase letter <= 'Z'
    // 'a' <= every lowercase letter <= 'z'
    // 'Z' < 'a' (this breaks if the encoding puts lowercase before uppercase)
    while (str[i]) {
        if (str[i] < 'A')
            return 0;
        if (str[i] > 'z')
            return 0;
        if (str[i] > 'Z' && str[i] < 'a')
            return 0;
        i++;
    }

    return 1;
}

int main(void) {
    char *str = "Hello";
    c_putstr(str);
    c_putnbr(is_alpha(str));
    c_putchar('\n');
    str = "Hello!";
    c_putstr(str);
    c_putnbr(is_alpha(str));
    c_putchar('\n');
    str = "Hell0";
    c_putstr(str);
    c_putnbr(is_alpha(str));
    c_putchar('\n');
    str = "";
    c_putstr(str);
    c_putnbr(is_alpha(str));
    c_putchar('\n');
    return 0;
}