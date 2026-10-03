#include "libc.h"

// `return (unsigned char)s1[i] - (unsigned char)s2[i];`
// This returns an integer. Apparentely because when doing
// minus C applies integer promotion to the values. The result
// of a subtraction is an integer.

int c_strncmp(char *s1, char *s2, unsigned int n) {
    if (n == 0) return 0;
    unsigned int i = 0;
    while (i < n && s1[i] == s2[i] && s1[i] != '\0') { i++; }
	return (unsigned char)s1[i] - (unsigned char)s2[i];
}

int main(void) {
    c_putnbr(c_strncmp("Hello", "Hello", 4));
    c_putchar('\n');
    c_putnbr(c_strncmp("Hello", "hello", 4));
    c_putchar('\n');
    c_putnbr(c_strncmp("Hello", "Hello!", 4));
    c_putchar('\n');
    c_putnbr(c_strncmp("hello!", "Hello", 4));
    c_putchar('\n');
    return 0;
}