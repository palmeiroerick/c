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
}

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

    print_comb(comb, n);

    while (comb != end) {
        comb = next_comb(comb);
        write(1, ", ", 2);
        print_comb(comb, n);
    } 
}

int main(void) {
    combn(1);
    write(1, "\n", 1);
    combn(2);
    write(1, "\n", 1);
    combn(3);
    write(1, "\n", 1);
    combn(9);
    return 0;
}