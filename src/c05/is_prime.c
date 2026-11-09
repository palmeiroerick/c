#include "libc.h"

int is_prime(int n) {
    if (n <= 1) return 0;
    int i = 2;
    while(i <= n / i) {
        if (n % i == 0) return 0;
        i++;
    }
    return 1;
}

int main(void) {
    c_putnbr(is_prime(-1)); c_putchar('\n');
    c_putnbr(is_prime(0)); c_putchar('\n');
    c_putnbr(is_prime(2)); c_putchar('\n');
    c_putnbr(is_prime(3)); c_putchar('\n');
    c_putnbr(is_prime(4)); c_putchar('\n');
    c_putnbr(is_prime(5)); c_putchar('\n');
    c_putnbr(is_prime(13)); c_putchar('\n');
    c_putnbr(is_prime(23)); c_putchar('\n');
    c_putnbr(is_prime(32)); c_putchar('\n');
    c_putnbr(is_prime(67)); c_putchar('\n');
    c_putnbr(is_prime(101)); c_putchar('\n');
    c_putnbr(is_prime(67)); c_putchar('\n');
    c_putnbr(is_prime(1001)); c_putchar('\n');
    c_putnbr(is_prime(1021)); c_putchar('\n');
    return 0;
}