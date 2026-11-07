#include "libc.h"

int factorial_iterative(int n) {
    if (n < 0) return 0;
    int result = 1;
    while (n > 1) { result *= n; n--; }
    return result;
}

int factorial_recursive(int n) {
    if (n < 0) return 0;
    if (n <= 1) return 1;
    return (n * factorial_recursive(n-1));
}

int main(void) {
    c_putnbr(factorial_recursive(-1));
    c_putchar('\n');
    c_putnbr(factorial_recursive(0));
    c_putchar('\n');
    c_putnbr(factorial_recursive(1));
    c_putchar('\n');
    c_putnbr(factorial_recursive(5));
    c_putchar('\n');
    c_putnbr(factorial_recursive(11));
    return 0;
}