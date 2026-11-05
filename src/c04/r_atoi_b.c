#include "libc.h"

// TODO: Base shouldn't allow '+' or '-'.
// TODO: Base shouldn't allow the same character twice
// TODO: A lookup table can eliminate the O(n*b) complexity of
//       searching linearly in the base for each character index.
//       Id est, O(n*b) -> O(n+b)


int r_strlen(char *str) {
    int size = 0;
    while (str[size]) size++;
    return size;
}

int r_strch(char *str, char ch) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            return i;
        }
    } 
    return -1;
}

int r_atoi_b(char *str, char *base) {
    int radix = r_strlen(base);
    if (radix < 2) return 0;

    while (*str == ' ') str++;

    int sign = 1;
    while (*str == '+' || *str == '-') {
        if (*str == '-') sign *= -1;
        str++;
    }

    int n = 0;
    while (*str != '\0') {
        int value = r_strch(base, *str);
        if (value == -1) break;
        n = n * radix + value;
        str++;
    }

    return n * sign;
}

int main(void) {
    c_putnbr(r_atoi_b("  ---+--+4242ab42", "0123456789"));
    c_putchar('\n');
    c_putnbr(r_atoi_b("ea", "0123456789abcdef"));
    c_putchar('\n');
    c_putnbr(r_atoi_b("xyz", "stuvwxyz"));
    c_putchar('\n');
    return 0;
}