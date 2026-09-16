#include "libc.h"

// void is_negative(int number) {
//     if (number < 0) {
//         c_putchar('N');
//     } else {
//         c_putchar('P');
//     }
// }

void is_negative(int number) {
    char c = (number < 0) ? 'N' : 'P';
    c_putchar(c);
}

int main(void) {
    is_negative(2);
    is_negative(0);
    is_negative(-2);
    return 0;
}