#include "libc.h"

void div_mod(const int *a, const int *b, int *div, int *mod) {
    *div = *a / *b;
    *mod = *a % *b;
}

int main(void) {
    int a = 37;
    int b = 3;
    int div;
    int mod;
    div_mod(&a, &b, &div, &mod);
    c_putnbr(div);
    c_putchar('\n');
    c_putnbr(mod);
    return 0;
}