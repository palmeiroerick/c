#include <unistd.h>

void c_putchar(char c) {
    write(1, &c, 1);
}

int main() {
    c_putchar(0x61);
    c_putchar(0x0A);
    return 0;
}
