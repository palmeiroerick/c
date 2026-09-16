#include "libc.h"

void alphabet(void) {
    char c = 'a';

    while (c <= 'z') {
        c_putchar(c);
        c++;
    }
}

void reverse_alphabet(void) {
    char c = 'z';

    while (c >= 'a') {
        c_putchar(c);
        c--;
    }
}

int main() {
    alphabet();
    c_putchar('\n');
    reverse_alphabet();
    return 0;
}