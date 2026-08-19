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
    // int lead = comb / 10;
    // int load = lead % 10;

    // when n == 3: comb % 10000000 == 3456789
    // i = 0; comb % 10^(0+1) == 9 - 0; if so the first digit was exhausted
    // i = 1; comb % 10^(1+1) == 9 - 1; if so the second digit was exhausted
    // So if the a digit was not exhausted increment it.
    // And also reset the right digits relative to the exhausted digit to the small possible
    // if comb == 379: return 389; if comb == 389: return 456

    // So we need a exhaustion verifier, and a 'expansion' while loop.
    // int power_of_ten = 10;
    int i = 0;

    while (comb % power(10, i + 1) == 9 - i) {
        i++;
    }

    int lead = comb / power(10, i + 1);
    int load = lead % 10;

    int a = 1;
    // when comb == 379; this should 'reset' it to 380
    comb = lead * power(10, i + 1) + power(10, i + 1) * a;
    a++;

    // then this loop should handle the final and adds + 9.
    // load = lead (37) % 10 == 7;
    // comb += load (7) + 2 
    while (a <= i) {
        comb += load * power(10, i + 1) + power(10, i + 1) * a;
        i++;
        a++;
    }

    // if (comb % 100000000 == 23456789) {
    //     int lead = comb / 100000000;
    //     comb = (lead * 100000000 + 100000000) + (lead * 10000000 + 20000000) + (lead * 1000000 + 3000000) + (lead * 100000 + 400000) + (lead * 10000 + 50000) + (lead * 1000 + 6000) + (lead * 100 + 700) + (lead * 10 + 80) + (lead * 1 + 9);
    // } else if (comb % 10000000 == 3456789) {
    //     int lead = comb / 10000000;
    //     int load = lead % 10;
    //     comb = (lead * 10000000 + 10000000) + (load * 1000000 + 2000000) + (load * 100000 + 300000) + (load * 10000 + 40000) + (load * 1000 + 5000) + (load * 100 + 600) + (load * 10 + 70) + (load * 1 + 8);
    // } else if (comb % 1000000 == 456789) {
    //     int lead = comb / 1000000;
    //     int load = lead % 10;
    //     comb = (lead * 1000000 + 1000000) + (load * 100000 + 200000) + (load * 10000 + 30000) + (load * 1000 + 4000) + (load * 100 + 500) + (load * 10 + 60) + (load * 1 + 7);
    // } else if (comb % 100000 == 56789) {
    //     int lead = comb / 100000;
    //     int load = lead % 10;
    //     comb = (lead * 100000 + 100000) + (load * 10000 + 20000) + (load * 1000 + 3000) + (load * 100 + 400) + (load * 10 + 50) + (load * 1 + 6);
    // } else if (comb % 10000 == 6789) {
    //     int lead = comb / 10000;
    //     int load = lead % 10;
    //     comb = (lead * 10000 + 10000) + (load * 1000 + 2000) + (load * 100 + 300) + (load * 10 + 40) + (load + 5);
    // } else if (comb % 1000 == 789) {
    //     int lead = comb / 1000;
    //     comb = (lead * 1000 + 1000) + ((lead % 10 + 2) * 100) + ((lead % 10 + 3) * 10) + (lead % 10 + 4);
    // } else if (comb % 100 == 89) {
    //     int lead = comb / 100;
    //     comb = (lead * 100 + 100) + ((lead % 10 + 2) * 10) + (lead % 10 + 3);
    // } else if (comb % 10 == 9) {
    //     int lead = comb / 10;
    //     comb = (lead * 10 + 10) + (lead % 10 + 2);
    // } else {
    //     comb++; // comb = (lead * 1 + 1)
    // }

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

    while (comb <= end) {
        print_comb(comb, n);
        comb = next_comb(comb);
    } 
}

int main(void) {
    combn(3);
    return 0;
}