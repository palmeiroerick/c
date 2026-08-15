#include <unistd.h>

void print_comb(int comb, const int n) {
    char str[n];
    int i = 0;

    while (comb > 0) {
        str[i] = comb % 10 + '0';
        comb = comb / 10;
        i++;
    }

    if (i < n) {
        str[i] = '0';
        i++;
    }

    while (i >= 0) {
        write(1, &str[i], 1);
        i--;
    }

    write(1, ", ", 2);
}

// // Do not handle power(0, 0);
int power(const int base, const int exp) {
    // if (exp == 0)
    //     return 1;

    int result = 1;

    for (int i = 0; i < exp; i++) {
        result *= base;
    }

    return result;
}

int next_comb(int comb, const int n) {
    int lead = comb / 10;
    int load = lead % 10;

    /* How to get at the start:
        comb = 01 when n = 2
        comb = 012 when n = 3
        comb = 0123 when n = 4
        ...
    */ 

    if (comb == 0) {
        comb = lead * power(lead, n) + power(lead, n);
    }

    return comb;
}

void combn(const int n) {
    int comb = 0;

    // TODO: How to define the max value for n length combinations?
    while (comb <= 89) {
        print_comb(comb, n);
        comb = next_comb(comb, n);
    } 
}

int main(void) {
    combn(2);
    // write(1, "\n", 1);
    // combn(2);
    // write(1, "\n", 1);
    // combn(3);
    // write(1, "\n", 1);
    // combn(4);
    // write(1, "\n", 1);
    // combn(8);
    // combn(9);
    return 0;
}