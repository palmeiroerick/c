#include "libc.h"

// void letters_v1(const char start, const char end, const int8_t step) {
//     int8_t i = 0;
//     int8_t diff = 0;
//     char c = start;
//
//     // TODO: The range of `start` and `end` is the lowercase letters
//     // TODO: What shoud the limit of the step be?
//
//     if (step > 0) {
//         if (start > end) {
//             // start: 20, end: 6 -> 12
//             // (26 + end) - start
//             diff = (26 + end) - start;
//             while (i <= diff) {
//                 write(1, &c, 1);
//                 c += step;
//                 i += step;
//                 if (c > 'z') {
//                     c -= 26;
//                 }
//             }
//         }
//         else if (end > start) {
//             // start: 6, end: 20 -> 14
//             // end - start
//             diff = end - start;
//             while (i <= diff) {
//                 write(1, &c, 1);
//                 c += step;
//                 i += step;
//             }
//         }
//     }
//
//     else if (step < 0) {
//         if (start > end) {
//             // start: 20, end = 6 -> 14
//             // start - end
//             diff = start - end;
//             while (i <= diff) {
//                 write(1, &c, 1);
//                 c += step;
//                 i = i + (step * -1);
//             }
//         }
//         else if (end > start) {
//             // start: 6, end: 20 -> 12
//             // (26 + start) - end
//             diff = (26 + start) - end;
//             while (i <= diff) {
//                 write(1, &c, 1);
//                 c += step;
//                 i = i + (step * -1);
//                 if (c < 'a') {
//                     c += 26;
//                 }
//             }
//         }
//     }
// }

// // How to implement a function that can cyclic wrap around
// // For example, if I want to print from 't' to 'f' in a step of 2 positive: "tvxzbdf"
// void letters(const char start, const char end, const int8_t step) {
//     int8_t i = 0;
//     int8_t diff = 0;
//     char c = start;
//
//     // TODO: The range of `start` and `end` is the lowercase letters
//     // TODO: What shoud the limit of the step be?
//
//     if (step > 0) {
//         if (start > end) {
//             diff = (26 + end) - start;
//         } else {
//             diff = end - start;
//         }
//         while (i <= diff) {
//             write(1, &c, 1);
//             c += step;
//             i += step;
//             if (c > 'z') {
//                 c -= 26;
//             }
//         }
//     }
//
//     else if (step < 0) {
//         if (start > end) {
//             diff = start - end;
//         } else {
//             diff = (26 + start) - end;
//         }
//         while (i <= diff) {
//             write(1, &c, 1);
//             c += step;
//             i = i + (step * -1);
//             if (c < 'a') {
//                 c += 26;
//             }
//         }
//     }
// }

void letters(const char start, const char end, const int step) {
    char c = start;
    int i = 0;

    const int mask = step >> ((sizeof(int) * 8) - 1);
    const int abs_step = (step ^ mask) - mask;

    const int sign = (step > 0) - (step < 0);
    const int diff = (sign * (end - start) + 26) % 26;

    while (i <= diff) {
        c_putchar(c);
        i += abs_step;
        c = 'a' + (c - 'a' + step + 26) % 26;
    }

    c_putchar('\n');
}

int main() {
    letters('t', 'f', 2);
    letters('f', 't', 2);
    letters('t', 'f', -2);
    letters('f', 't', -2);
    return 0;
}