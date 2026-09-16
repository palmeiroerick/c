#include "libc.h"

// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main(void) {
    int a = 7;
    int b = 9;
    swap(&a, &b);
    c_putnbr(a);
    c_putchar('\n');
    c_putnbr(b);
    return 0;
}