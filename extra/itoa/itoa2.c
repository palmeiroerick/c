#include <stdio.h>

#define BSIZE 12

char *naive_itoa2(int num, char *str) {
    size_t size = 0;
    int divisor = 1;

    // if (num == 0) { *str-- = '0'; return (str + 1); }

    if (num < 0) str[size++] = '-';
    if (num > 0) num = -num;

    while (num / divisor <= -10) divisor *= 10;

    while (divisor > 0) {
        str[size++] = '0' - num / divisor % 10;
        divisor /= 10;
    }

    str[size] = '\0';

    return str;
}


int main(void) {
    char buffer[BSIZE] = "";
    printf("%s\n", naive_itoa2(0x7fffffff, buffer));
    printf("%s\n", naive_itoa2(0x80000000, buffer));
    printf("%s\n", naive_itoa2(0xffffffff, buffer));
    printf("%s\n", naive_itoa2(0x00000000, buffer));
    printf("%s\n", naive_itoa2(0x00000045, buffer));
    return 0;
}
