#include "libc.h"

void c_putchar(char c) {
    write(1, &c, 1);
}