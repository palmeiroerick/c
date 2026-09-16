#include <unistd.h>

void putstr(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    write(1, str, i);
}

int main(void) {
    putstr("Hello, World!");
    return 0;
}