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
                int lead = comb / 10000;
                comb = (lead * 10000 + 10000) + (lead * 1000 + 2000) + (lead * 100 + 300) + (lead * 10 + 40) + (lead + 5);
            } else if (comb % 1000 == 789) {
                int lead = comb / 1000;
                comb = (lead * 1000 + 1000) + ((lead % 10 + 2) * 100) + ((lead % 10 + 3) * 10) + (lead % 10 + 4);
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
    } else if (n == 6) {
        comb = 12345;
        while (comb <= 456789) {
            print_comb(comb, n);
            write(1, ", ", 2);
            if (comb % 100000 == 56789) {
                int lead = comb / 100000;
                comb = (lead * 100000 + 100000) + (lead * 10000 + 20000) + (lead * 1000 + 3000) + (lead * 100 + 400) + (lead * 10 + 50) + (lead * 1 + 6);
            } else if (comb % 10000 == 6789) {
                int lead = comb / 10000;
                int load = lead % 10;
                comb = (lead * 10000 + 10000) + (load * 1000 + 2000) + (load * 100 + 300) + (load * 10 + 40) + (load + 5);
            } else if (comb % 1000 == 789) {
                int lead = comb / 1000;
                comb = (lead * 1000 + 1000) + ((lead % 10 + 2) * 100) + ((lead % 10 + 3) * 10) + (lead % 10 + 4);
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
    } else if (n == 7) {
        comb = 123456;
        while (comb <= 3456789) {
            print_comb(comb, n);
            write(1, ", ", 2);
            if (comb % 1000000 == 456789) {
                int lead = comb / 1000000;
                comb = (lead * 1000000 + 1000000) + (lead * 100000 + 200000) + (lead * 10000 + 30000) + (lead * 1000 + 4000) + (lead * 100 + 500) + (lead * 10 + 60) + (lead * 1 + 7);
            } else if (comb % 100000 == 56789) {
                int lead = comb / 100000;
                int load = lead % 10;
                comb = (lead * 100000 + 100000) + (load * 10000 + 20000) + (load * 1000 + 3000) + (load * 100 + 400) + (load * 10 + 50) + (load * 1 + 6);
            } else if (comb % 10000 == 6789) {
                int lead = comb / 10000;
                int load = lead % 10;
                comb = (lead * 10000 + 10000) + (load * 1000 + 2000) + (load * 100 + 300) + (load * 10 + 40) + (load + 5);
            } else if (comb % 1000 == 789) {
                int lead = comb / 1000;
                comb = (lead * 1000 + 1000) + ((lead % 10 + 2) * 100) + ((lead % 10 + 3) * 10) + (lead % 10 + 4);
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
    } else if (n == 8) {
        comb = 1234567;
        while (comb <= 23456789) {
            print_comb(comb, n);
            write(1, ", ", 2);
            if (comb % 10000000 == 3456789) {
                int lead = comb / 10000000;
                comb = (lead * 10000000 + 10000000) + (lead * 1000000 + 2000000) + (lead * 100000 + 300000) + (lead * 10000 + 40000) + (lead * 1000 + 5000) + (lead * 100 + 600) + (lead * 10 + 70) + (lead * 1 + 8);
            } else if (comb % 1000000 == 456789) {
                int lead = comb / 1000000;
                int load = lead % 10;
                comb = (lead * 1000000 + 1000000) + (load * 100000 + 200000) + (load * 10000 + 30000) + (load * 1000 + 4000) + (load * 100 + 500) + (load * 10 + 60) + (load * 1 + 7);
            } else if (comb % 100000 == 56789) {
                int lead = comb / 100000;
                int load = lead % 10;
                comb = (lead * 100000 + 100000) + (load * 10000 + 20000) + (load * 1000 + 3000) + (load * 100 + 400) + (load * 10 + 50) + (load * 1 + 6);
            } else if (comb % 10000 == 6789) {
                int lead = comb / 10000;
                int load = lead % 10;
                comb = (lead * 10000 + 10000) + (load * 1000 + 2000) + (load * 100 + 300) + (load * 10 + 40) + (load + 5);
            } else if (comb % 1000 == 789) {
                int lead = comb / 1000;
                comb = (lead * 1000 + 1000) + ((lead % 10 + 2) * 100) + ((lead % 10 + 3) * 10) + (lead % 10 + 4);
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
    } else if (n == 9) {
        write(1, "012345679, 012345689, 012345789, 012346789, 012356789, 012456789, 013456789, 023456789, 123456789", 97);
    }
    // } else if (n == 9) {
    //     comb = 12345678;
    //     while (comb <= 123456789) {
    //         print_comb(comb, n);
    //         write(1, ", ", 2);
    //         if (comb % 100000000 == 23456789) {
    //             int lead = comb / 100000000;
    //             comb = (lead * 100000000 + 100000000) + (lead * 10000000 + 20000000) + (lead * 1000000 + 3000000) + (lead * 100000 + 400000) + (lead * 10000 + 50000) + (lead * 1000 + 6000) + (lead * 100 + 700) + (lead * 10 + 80) + (lead * 1 + 9);
    //         } else if (comb % 10000000 == 3456789) {
    //             int lead = comb / 10000000;
    //             int load = lead % 10;
    //             comb = (lead * 10000000 + 10000000) + (load * 1000000 + 2000000) + (load * 100000 + 300000) + (load * 10000 + 40000) + (load * 1000 + 5000) + (load * 100 + 600) + (load * 10 + 70) + (load * 1 + 8);
    //         } else if (comb % 1000000 == 456789) {
    //             int lead = comb / 1000000;
    //             int load = lead % 10;
    //             comb = (lead * 1000000 + 1000000) + (load * 100000 + 200000) + (load * 10000 + 30000) + (load * 1000 + 4000) + (load * 100 + 500) + (load * 10 + 60) + (load * 1 + 7);
    //         } else if (comb % 100000 == 56789) {
    //             int lead = comb / 100000;
    //             int load = lead % 10;
    //             comb = (lead * 100000 + 100000) + (load * 10000 + 20000) + (load * 1000 + 3000) + (load * 100 + 400) + (load * 10 + 50) + (load * 1 + 6);
    //         } else if (comb % 10000 == 6789) {
    //             int lead = comb / 10000;
    //             int load = lead % 10;
    //             comb = (lead * 10000 + 10000) + (load * 1000 + 2000) + (load * 100 + 300) + (load * 10 + 40) + (load + 5);
    //         } else if (comb % 1000 == 789) {
    //             int lead = comb / 1000;
    //             comb = (lead * 1000 + 1000) + ((lead % 10 + 2) * 100) + ((lead % 10 + 3) * 10) + (lead % 10 + 4);
    //         } else if (comb % 100 == 89) {
    //             int lead = comb / 100;
    //             comb = (lead * 100 + 100) + ((lead % 10 + 2) * 10) + (lead % 10 + 3);
    //         } else if (comb % 10 == 9) {
    //             int lead = comb / 10;
    //             comb = (lead * 10 + 10) + (lead % 10 + 2);
    //         } else {
    //             comb++;
    //         }
    //     }
    // }
}

int main(void) {
    combn(3);
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