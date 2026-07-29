#include <unistd.h>
#include <stdint.h>

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

// How to implement a function that can cyclic wrap around
// For example, if I want to print from 't' to 'f' in a step of 2 positive: "tvxzbdf"
void letters(const char start, const char end, const int8_t step) {
    int8_t i = 0;
    int8_t diff = 0;
    char c = start;

    // TODO: The range of `start` and `end` is the lowercase letters
    // TODO: What shoud the limit of the step be?

    if (step > 0) {
        if (start > end) {
            diff = (26 + end) - start;
        } else {
            diff = end - start;
        }
        while (i <= diff) {
            write(1, &c, 1);
            c += step;
            i += step;
            if (c > 'z') {
                c -= 26;
            }
        }
    }

    else if (step < 0) {
        if (start > end) {
            diff = start - end;
        } else {
            diff = (26 + start) - end;
        }
        while (i <= diff) {
            write(1, &c, 1);
            c += step;
            i = i + (step * -1);
            if (c < 'a') {
                c += 26;
            }
        }
    }
}

int main() {
    // alphabet();
    // reverse_alphabet();
    letters('t', 'f', 2);
    write(1, "\n", 1);
    letters('f', 't', 2);
    write(1, "\n", 1);
    letters('t', 'f', -2);
    write(1, "\n", 1);
    letters('f', 't', -2);
    write(1, "\n", 1);
    return 0;
}
