#include "libc.h"

// void c_putnbr(int nbr) {
//     char digits[10];
//     int length = 0; 

//     if (nbr == 0) {
//         write(1, "0", 1);
//         write(1, "\n", 1);
//         return;
//     }

//     if (nbr < 0) {
//         write(1, "-", 1);

//         while (nbr != 0) {
//             digits[length] = (nbr % 10) * -1 + '0';
//             nbr = nbr / 10;
//             length++;
//         }
//     } else {
//         while (nbr != 0) {
//             digits[length] = nbr % 10 + '0';
//             nbr = nbr / 10;
//             length++;
//         }
//     }

//     while (length > 0) {
//         write(1, &digits[length - 1], 1);
//         length--;
//     }
// }

// void c_putnbr(int nb) {
//     char c;

//     if (nb < 0) {
//         write(1, "-", 1);

//         if (nb <= -10)
//             c_putnbr(-(nb / 10));

//         c = -(nb % 10) + '0';
//         write(1, &c, 1);
//         return;
//     }

//     if (nb >= 10)
// 		c_putnbr(nb / 10);

//     c = nb % 10 + '0';
//     write(1, &c, 1);
// }

// void print_comb(int comb, const int n) {
//     char str[n];
//     int i = 0;
//
//     while (comb > 0) {
//         str[i] = comb % 10 + '0';
//         comb = comb / 10;
//         i++;
//     }
//
//     if (i < n) {
//         str[i] = '0';
//         i++;
//     }
//
//     while (i >= 0) {
//         write(1, &str[i], 1);
//         i--;
//     }
// }


void c_putnbr(int n) {
    char c;
    int q, r;

    q = n / 10;
    r = n % 10;

    if (n < 0) {
        c_putchar('-');
        q = -q;
        r = -r;
    }

    if (q != 0)
        c_putnbr(q);

    c = r + '0';
    c_putchar(c);
}

int main(void) {
    c_putnbr(1234567890);
    c_putchar('\n');
    c_putnbr(0x7fffffff);
    c_putchar('\n');
    c_putnbr(0x80000000);
    c_putchar('\n');
    c_putnbr(0xffffffff);
    c_putchar('\n');
    c_putnbr(0x00000000);
    c_putchar('\n');
    c_putnbr(0x00000001);
    c_putchar('\n');
    c_putnbr(42);
    c_putchar('\n');
    c_putnbr(-42);
    c_putchar('\n');
    return 0;
}
