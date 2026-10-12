#include <stdio.h>

#define BSIZE 12

const int powers_of_ten[10] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };

size_t get_digits_count(int num) {
    size_t l = 0;

    if (num <= -powers_of_ten[9] || num >= powers_of_ten[9]) return 10;

    if (num < 0) num = -num;

    while (num >= powers_of_ten[++l]);

    return l;
}

char *naive_itoa3(int num, char *str) {
    size_t size = 0;
    size_t l = get_digits_count(num);
    int digit;

    if (num < 0) str[size++] = '-'; else num = -num;

    // while (l > 0) str[size++] = '0' - num / powers_of_ten[--l] % 10;
    while (l > 0) {
        digit = num / powers_of_ten[--l];
        str[size++] = '0' - digit;
        num -= digit * powers_of_ten[l];
    }

    str[size] = '\0';

    return str;
}

int main(void) {
    char buffer[BSIZE] = "";
    printf("%s\n", naive_itoa3(0x7fffffff, buffer));
    printf("%s\n", naive_itoa3(0x80000000, buffer));
    printf("%s\n", naive_itoa3(0xffffffff, buffer));
    printf("%s\n", naive_itoa3(0x00000000, buffer));
    printf("%s\n", naive_itoa3(0x00000045, buffer));
    return 0;
}
