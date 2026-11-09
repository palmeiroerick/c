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

int next_prime(int n) {
    while(!is_prime(n)) n++;
    return n;
}

int main(void) {
    c_putnbr(next_prime(0)); c_putchar('\n');
    c_putnbr(next_prime(2)); c_putchar('\n');
    c_putnbr(next_prime(3)); c_putchar('\n');
    c_putnbr(next_prime(4)); c_putchar('\n');
    c_putnbr(next_prime(16)); c_putchar('\n');
    c_putnbr(next_prime(24)); c_putchar('\n');
    c_putnbr(next_prime(32)); c_putchar('\n');
    c_putnbr(next_prime(100)); c_putchar('\n');
    c_putnbr(next_prime(1000)); c_putchar('\n');
    return 0;
}