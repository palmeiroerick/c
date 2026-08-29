#include <unistd.h>

void putchr(char c) {
    write(1, &c, 1);
}

void putnbr(int n) {
    char c;
    int q, r;

    q = n / 10;
    r = n % 10;

    if (n < 0) {
        putchr('-');
        q = -q;
        r = -r;
    }

    if (q != 0)
        putnbr(q);

    c = r + '0';
    putchr(c);
}

void ft_ft(int *n) {
    *n = 42;
}

int main(void) {
    int n = 24;
    putnbr(n);
    ft_ft(&n);
    putnbr(n);
    return 0;
}