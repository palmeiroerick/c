#include <unistd.h>

void c_putstr(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    write(1, str, i);
}

int main(void) {
    c_putstr("Hello, World!");
    return 0;
}