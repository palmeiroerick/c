#include "libc.h"

int char_is_digit(char c) {
    return c >= '0' && c <= '9';
}

int r_atoi (char *str) {
    while (*str == ' ') str++;

    int sign = 1;
    while (*str == '+' || *str == '-')
        if (*str++ == '-') sign *= -1;

    // Not digit finded after the spaces or signs.
    // Not sure how this error should be represented.
    if (!char_is_digit(*str)) return 0;

    const char *start = str;
    while (char_is_digit(*(++str)));

    int n = 0, p = 1;
    while (--str >= start)
        n += (*str - '0') * p, p *= 10;

    return n * sign;
}

// int r_atoi (char *str) {
//     while (*str == ' ') str++;

//     int sign = 1;
//     while (*str == '+' || *str == '-')
//         if (*str++ == '-') sign *= -1;

//     // Not digit finded after the spaces or signs.
//     // Not sure how this error should be represented.
//     if (!char_is_digit(*str)) return 0;

//     int n = 0;
//     while (char_is_digit(*str))
//         n = 10 * n + (*str++ - '0');

//     return n * sign;
// }

int main(void) {
    c_putnbr(r_atoi("  ---+--+9243ab567"));
    c_putchar('\n');
    return 0;
}