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

void ultimate_div_mod(int *a, int *b) {
    int temp = *a / *b;
    *b = *a % *b;
    *a = temp;
}

int main(void) {
    int a = 37;
    int b = 3;
    ultimate_div_mod(&a, &b);
    putnbr(a);
    putchr('\n');
    putnbr(b);
    return 0;
}