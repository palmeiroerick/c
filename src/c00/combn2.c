#include "libc.h"

int power(const int base, int exp) {
    int result = 1;

    while (exp > 0) {
        result *= base;
        exp--;
    }

    return result;
}

int next_comb(int comb) {
    int i = 0;

    while ((comb % power(10, i + 1)) / power(10, i) == 9 - i) {
        i++;
    }

    if (i == 0) {
        return comb + 1;
    }

    int lead = comb / power(10, i) + 1;
    int load = lead % 10;

    comb = lead * power(10, i);

    int k = 1;

    while (k <= i) {
        comb += (load + k) * power(10, i - k);
        k++;
    }

    return comb;
}

void combn(const int n) {
    int comb = 0;
    int end = 0;
    int i;

    i = 0;

    while (i < n) {
        comb += (n - i - 1) * power(10, i);
        i++;
    }

    i = 0;

    while (i < n) {
        end += (10 - n + i) * power(10, n - i - 1);
        i++;
    }

    c_putnbr(comb);

    while (comb != end) {
        comb = next_comb(comb);
        c_putstr(", ");
        c_putnbr(comb);
    } 
}

int main(void) {
    combn(1);
    c_putchar('\n');
    combn(2);
    c_putchar('\n');
    combn(3);
    c_putchar('\n');
    combn(9);
    return 0;
}