#include <unistd.h>

void numbers(void) {
    char c = '0';

    while (c <= '9') {
        write(1, &c, 1);
        c++;
    }
}

int main(void) {
    numbers();
    return 0;
}