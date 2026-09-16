#include "libc.h"

void ft_ft(int *n) {
    *n = 42;
}

int main(void) {
    int n = 24;
    c_putnbr(n);
    ft_ft(&n);
    c_putchar('\n');
    c_putnbr(n);
    return 0;
}