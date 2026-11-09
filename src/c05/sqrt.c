#include "libc.h"

// int r_sqrt(int n) {
//     int i = 0;
//     while (i*i < n) i++;
//     if (i*i == n) return i;
//     return 0;
// }

int r_sqrt(int n) {
    if (n < 0) return 0;
    if (n <= 1) return n;
    int left = 1;
    int right = n / 2;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2; 
        if (mid * mid == n) return mid;
        if (mid * mid > n) right = mid - 1;
        else left = mid + 1;
    }
    return 0;
}

int main(void) {
    c_putnbr(r_sqrt(-1)); c_putchar('\n');
    c_putnbr(r_sqrt(0)); c_putchar('\n');
    c_putnbr(r_sqrt(2)); c_putchar('\n');
    c_putnbr(r_sqrt(4)); c_putchar('\n');
    c_putnbr(r_sqrt(9)); c_putchar('\n');
    c_putnbr(r_sqrt(25)); c_putchar('\n');
    c_putnbr(r_sqrt(144)); c_putchar('\n');
    c_putnbr(r_sqrt(256)); c_putchar('\n');
    c_putnbr(r_sqrt(55)); c_putchar('\n');
    return 0;
}