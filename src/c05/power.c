#include "libc.h"

int power_iterative(int n, int power) {
    if (power < 0) return 0;
    int result = 1;
    int i = 0;
    while (i < power) { result *= n; i++; }
    return result;
}

int power_recursive(int n, int power) {
    if (power < 0) return 0;
    if (power == 0) return 1;
    return (n * power_recursive(n, power-1));
}

int main(void) {
    c_putnbr(power_iterative(10, -1));
    c_putchar('\n');
    c_putnbr(power_iterative(0, 0));
    c_putchar('\n');
    c_putnbr(power_iterative(1, 1));
    c_putchar('\n');
    c_putnbr(power_iterative(-2, 5));
    c_putchar('\n');
    c_putnbr(power_iterative(7, 7));

    c_putchar('\n');

    c_putnbr(power_recursive(10, -1));
    c_putchar('\n');
    c_putnbr(power_recursive(0, 0));
    c_putchar('\n');
    c_putnbr(power_recursive(1, 1));
    c_putchar('\n');
    c_putnbr(power_recursive(-2, 5));
    c_putchar('\n');
    c_putnbr(power_recursive(7, 7));
    return 0;
}