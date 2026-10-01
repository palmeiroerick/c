#include "libc.h"

// TODO: Why casting to unsigned char
// TODO: Do casting to an unsigned char after the loop in the
// return expression will always produces the same behaviour?
// TODO: How the glibc implements this?
// TODO: Is there other ways of comparing strings? rather than lexicographycally?
// TODO: How to compare string slices? instead of c strings.
// TODO: How to describe this function using formal math [I am curious].

// int c_strcmp(char *s1, char *s2) {
//     int i = 0;
//     while (s1[i] && s2[i]) i++;
//     if (s1[i] && !s2[i]) return -1;
//     if (!s1[i] && s2[i]) return 1;
//     return 0;
// }

// Using the pointers direct without indexing
// int c_strcmp(char *s1, char *s2) {
//     while (*s1 && *s2) { s1++; s2++; }
//     if (*s1 && !*s2) return -1;
//     if (!*s1 && *s2) return 1;
//     return 0;
// }

// The function just ask for a negative value, so:
// int c_strcmp(char *s1, char *s2) {
//     while (*s1 && *s2) { s1++; s2++; }
//     return *s1 - *s2;
// }

// All the previous functions return 0 when s1 and s2
// have the same size, but the correct behavior is to
// return 0 only when both are equal.
// The semantic is based on lexicography.
// When the first differing character in s1 is less than the
// correponding character in s2, s1 is lexicographycally
// smaller and the result is negative.
// When it is greater, the result is positive.
// If both strings reach null at the same position, they
// are equal and the result is 0.

// int c_strcmp(char *s1, char *s2) {
//     while (*s1 == *s2 && *s1 != '\0') { s1++; s2++; }
//     return *s1 - *s2;
// }

// The comparation is done using unsigned characters.
// According with the manual. (Why?)
// int c_strcmp(char *s1, char *s2) {
//     unsigned char *p1 = (unsigned char *)s1;
//     unsigned char *p2 = (unsigned char *)s2;
//     while (*p1 == *p2 && *p1 != '\0') { p1++; p2++; }
//     return *p1 - *p2;
// }

// This returns different numbers.
// Why do casting this way produces different behaviour?
// int c_strcmp(char *s1, char *s2) {
//     while (*s1 == *s2 && *s1 != '\0') { s1++; s2++; }
//     return (unsigned char *)s1 - (unsigned char *)s2;
// }
// The freaking dereference :)
int c_strcmp(char *s1, char *s2) {
    while (*s1 == *s2 && *s1 != '\0') { s1++; s2++; }
	return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int main(void) {
    c_putnbr(c_strcmp("Hello", "Hello"));
    c_putchar('\n');
    c_putnbr(c_strcmp("Hello", "hello"));
    c_putchar('\n');
    c_putnbr(c_strcmp("Hello", "Hello!"));
    c_putchar('\n');
    c_putnbr(c_strcmp("Hello!", "Hello"));
    c_putchar('\n');
    return 0;
}