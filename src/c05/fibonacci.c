#include "libc.h"

int fibonacci(int n) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n <= 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
    c_putnbr(fibonacci(-1)); c_putchar('\n');
    c_putnbr(fibonacci(0)); c_putchar('\n');
    c_putnbr(fibonacci(1)); c_putchar('\n');
    c_putnbr(fibonacci(2)); c_putchar('\n');
    c_putnbr(fibonacci(3)); c_putchar('\n');
    c_putnbr(fibonacci(7)); c_putchar('\n');
    c_putnbr(fibonacci(12)); c_putchar('\n');
    return 0;
}