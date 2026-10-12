#include <stdio.h>

#define BSIZE 12

char *naive_itoa(int num, char *str) {
    str += BSIZE - 1;
    *str-- = '\0';

    if (num == 0) { *str-- = '0'; return (str + 1); }

    int is_negative = num < 0;

    if (num > 0) num = -num;

    while (num < 0) {
        *str-- = '0' - num % 10;
        num /= 10;
    }

    if (is_negative) *str-- = '-';

    return (str + 1);
}

int main(void) {
    char buffer[BSIZE] = "";
    printf("%s\n", naive_itoa(0x7fffffff, buffer));
    printf("%s\n", naive_itoa(0x80000000, buffer));
    printf("%s\n", naive_itoa(0xffffffff, buffer));
    printf("%s\n", naive_itoa(0x00000000, buffer));
    printf("%s\n", naive_itoa(0x00000045, buffer));
    return 0;
}
