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

int c_strlen(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    return i;
}

int main(void) {
    putnbr(c_strlen("Hello, World!"));
    return 0;
}