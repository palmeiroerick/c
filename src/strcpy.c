#include <unistd.h>
#include <stdint.h>

void putstr(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    write(1, str, i);
}

void putstrmem(char *str) {
    char digits[16] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };

    int size = sizeof(str);

    char address_str[size + 2];
    address_str[0] = '0';
    address_str[1] = 'x';

    uintptr_t address, high_nibble, low_nibble;

    address = (uintptr_t)str;

    high_nibble = address / 16;
    low_nibble = address % 16;
    address_str[2] = digits[low_nibble];

    int i = 1;
    while (i < size * 2) {
        low_nibble = high_nibble % 16;
        high_nibble = high_nibble / 16;
        address_str[i+2] = digits[low_nibble];
        i++;
    }

    putstr(address_str);
    write(1, " -> ", 4);
    putstr(str);
    write(1, "\n", 1);
}

// char *c_stpcpy(char *restrict dst, const char *restrict src) {

// }

int main(void) {
    char *hello = "Hello, World!";
    char *copy = hello;
    putstrmem(hello);
    putstrmem(copy);
    return 0;
}