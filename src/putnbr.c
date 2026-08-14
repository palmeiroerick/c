#include <unistd.h>

// void putnbr(int nbr) {
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

// void putnbr(int nb) {
//     char c;

//     if (nb < 0) {
//         write(1, "-", 1);

//         if (nb <= -10)
//             putnbr(-(nb / 10));

//         c = -(nb % 10) + '0';
//         write(1, &c, 1);
//         return;
//     }

//     if (nb >= 10)
// 		putnbr(nb / 10);

//     c = nb % 10 + '0';
//     write(1, &c, 1);
// }

void putchr(char c) {
    write(1, &c, 1);
}

void putnbr(int n) {
    char c;
    int q, r;

    q = n / 10;
    r = n % 10;

    if (n < 0) {
        putchr('-');
        q = -q;
        r = -r;
    }

    if (q != 0)
        putnbr(q);

    c = r + '0';
    putchr(c);
}

int main(void) {
    putnbr(1234567890);
    write(1, "\n", 1);
    putnbr(0x7fffffff);
    write(1, "\n", 1);
    putnbr(0x80000000);
    write(1, "\n", 1);
    putnbr(0xffffffff);
    write(1, "\n", 1);
    putnbr(0x00000000);
    write(1, "\n", 1);
    putnbr(0x00000001);
    write(1, "\n", 1);
    putnbr(42);
    write(1, "\n", 1);
    putnbr(-42);
    write(1, "\n", 1);
    return 0;
}