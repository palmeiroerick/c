#include <unistd.h>

// void is_negative(int number) {
//     if (number < 0) {
//         write(1, "N", 1);
//     } else {
//         write(1, "P", 1);
//     }
// }

void is_negative(int number) {
    char c = (number < 0) ? 'N' : 'P';
    write(1, &c, 1);
}

int main(void) {
    is_negative(2);
    is_negative(0);
    is_negative(-2);
    return 0;
}