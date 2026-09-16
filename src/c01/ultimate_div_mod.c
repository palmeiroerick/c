#include "libc.h"

void ultimate_div_mod(int *a, int *b) {
    int div = *a / *b;
    *b = *a % *b;
    *a = div;
}

int main(void) {
    int a = 37;
    int b = 3;
    ultimate_div_mod(&a, &b);
    c_putnbr(a);
    c_putchar('\n');
    c_putnbr(b);
    return 0;
}