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

void swap(int *a, int *b) {
    // int temp = *a;
    // *a = *b;
    // *b = temp;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main(void) {
    int a = 7;
    int b = 9;
    swap(&a, &b);
    putnbr(a);
    putchr('\n');
    putnbr(b);
    return 0;
}