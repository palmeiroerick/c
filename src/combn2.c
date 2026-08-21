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

int power(const int base, const int exp) {
    int result = 1;

    for (int i = 0; i < exp; i++) {
        result *= base;
    }

    return result;
}

int next_comb(int comb) {
    int i = 0;

    // this while gives i the value of 10 when comb == 123456789, it should give the value 9
    // but this function should not be called with the maximum possible value of comb
    // is this behaviour a bug? I think is reasonable to not let this function to execute with
    // tha maximum possible valie.
    // Also 10^10 overflow i32, and 10^9 * k will probably too.
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

    // This codition creates a bug for the maximum possible value.
    // It get next comb right after printing the previous one.
    // When n = 9 we have end = 123456789, the last valid value for comb also is
    // 123456789. The while prints it and get the next one, the problem is that 
    // the next value will overflow and when the while verify the condition
    // it will be false, this make an infinity loop with a overflowed comb.
    // So I should think in a way of print_comb after getting the next, but for that
    // I need to garantee that the first comb is printed. (There is other way?)
    while (comb <= end) {
        print_comb(comb, n);
        comb = next_comb(comb);
    } 
}

int main(void) {
    combn(9);
    return 0;
}