#include "libc.h"

void c_putnbr(int n) {
    char c;
    int q, r;

    q = n / 10;
    r = n % 10;

    if (n < 0) {
        c_putchar('-');
        q = -q;
        r = -r;
    }

    if (q != 0)
        c_putnbr(q);

    c = r + '0';
    c_putchar(c);
}