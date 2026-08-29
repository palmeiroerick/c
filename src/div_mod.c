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
    putnbr(div);
    putchr('\n');
    putnbr(mod);
    return 0;
}