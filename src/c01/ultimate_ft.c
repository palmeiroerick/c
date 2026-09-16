#include "libc.h"

void ultimate_ft(int *********n) {
    *********n = 42;
}

int main(void) {
    int n = 24;
    int *ptr1 = &n;
    int **ptr2 = &ptr1;
    int ***ptr3 = &ptr2;
    int ****ptr4 = &ptr3;
    int *****ptr5 = &ptr4;
    int ******ptr6 = &ptr5;
    int *******ptr7 = &ptr6;
    int ********ptr8 = &ptr7;
    c_putnbr(n);
    ultimate_ft(&ptr8);
    c_putchar('\n');
    c_putnbr(n);
    return 0;
}