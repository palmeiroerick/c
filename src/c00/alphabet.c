#include <unistd.h>

void alphabet(void) {
    char c = 'a';

    while (c <= 'z') {
        write(1, &c, 1);
        c++;
    }
}

void reverse_alphabet(void) {
    char c = 'z';

    while (c >= 'a') {
        write(1, &c, 1);
        c--;
    }
}

int main() {
    alphabet();
    write(1, "\n", 1);
    reverse_alphabet();
    return 0;
}
