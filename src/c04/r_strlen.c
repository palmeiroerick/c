#include "libc.h"

size_t r_strlen(const char *str) {
    size_t size = 0;
    while (*str++) size++;
    return size;
}

int main(void) {
    char *hello = "Hello, World!";
    c_putnbr(r_strlen(hello));
    c_putchar('\n');
    const char foo[] = "bar";
    c_putnbr(r_strlen(foo));
    return 0;
}