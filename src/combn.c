#include <unistd.h>

// int next_comb(int comb) {
//     comb++;
//     return comb;
// }

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

void combn(const int n) {
    int comb;
    char c;

    if (n == 1) {
        comb = 0;
        while (comb <= 9) {
            c = comb + '0';
            write(1, &c, 1);
            write(1, ", ", 2);
            comb++;
        }
    } else if (n == 2) {
        comb = 1;
        while (comb <= 89) {
            print_comb(comb, n);
            write(1, ", ", 2);
            if (comb % 10 == 9) {
                comb++;
                comb = comb + comb / 10 + 1;
            } else {
                comb++;
            }
        }
    } else if (n == 3) {
        comb = 12;
        while (comb <= 789) {
            print_comb(comb, n);
            write(1, ", ", 2);
            if (comb % 100 == 89) {
                int lead = comb / 100;
                comb = (lead * 100 + 100) + (lead * 10 + 20) + (lead + 3);
            } else if (comb % 10 == 9) {
                int lead = comb / 10;
                comb = (lead * 10 + 10) + (lead % 10 + 2);
            } else {
                comb++;
            }
        }
    } else if (n == 4) {
        comb = 123;
        while (comb <= 6789) {
            print_comb(comb, n);
            write(1, ", ", 2);
            if (comb % 1000 == 789) {
                int lead = comb / 1000;
                comb = (lead * 1000 + 1000) + (lead * 100 + 200) + (lead * 10 + 30) + (lead + 4);
            } else if (comb % 100 == 89) {
                int lead = comb / 100;
                comb = (lead * 100 + 100) + ((lead % 10 + 2) * 10) + (lead % 10 + 3);
            } else if (comb % 10 == 9) {
                int lead = comb / 10;
                comb = (lead * 10 + 10) + (lead % 10 + 2);
            } else {
                comb++;
            }
        }
    } else if (n == 5) {
        comb = 1234;
        while (comb <= 56789) {
            print_comb(comb, n);
            write(1, ", ", 2);
            if (comb % 10000 == 6789) {
                
            }
            if (comb % 1000 == 789) {
                int lead = comb / 1000;
                comb = (lead * 1000 + 1000) + (lead * 100 + 200) + (lead * 10 + 30) + (lead + 4);
            } else if (comb % 100 == 89) {
                int lead = comb / 100;
                comb = (lead * 100 + 100) + ((lead % 10 + 2) * 10) + (lead % 10 + 3);
            } else if (comb % 10 == 9) {
                int lead = comb / 10;
                comb = (lead * 10 + 10) + (lead % 10 + 2);
            } else {
                comb++;
            }
        }
    }
}

int main(void) {
    combn(1);
    write(1, "\n", 1);
    combn(2);
    write(1, "\n", 1);
    combn(3);
    write(1, "\n", 1);
    combn(4);
    write(1, "\n", 1);
    combn(5);
    // combn(9);
    return 0;
}