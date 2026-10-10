#include <unistd.h>

size_t r_strlen(const char *str) {
    size_t size = 0;
    while (*str++) size++;
    return size;
}

// Pointer Mutation:
//     When traversing a string using pointer arithmetic, and
//     using the same pointer (str) again to write the string, the 
//     write() attempts to write size bytes from str's current
//     position, not from the beginning of the string.
//     In other words when you change the value of a pointer (or any
//     kind of variable) you cannot treat it as the original value.
// void r_putstr(const char *str) {
//     size_t size = 0;
//     while (*str++) size++;
//     write(1, str, size);
// }

// One system call for the entire string rather than a system
// call for every char [ while (*str) write(1, str++, 1); ]
void r_putstr(const char *str) {
    write(1, str, r_strlen(str));
}

int main(void) {
    char *hello = "Hello, World!";
    r_putstr(hello);
    write(1, "\n", 1);
    const char foo[] = "bar";
    r_putstr(foo);
    return 0;
}