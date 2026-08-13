#include <unistd.h>

void putnbr(int nbr) {
    char digits[10];
    int length = 0; 

    if (nbr == 0) {
        write(1, "0", 1);
        write(1, "\n", 1);
        return;
    }

    if (nbr < 0) {
        write(1, "-", 1);

        while (nbr != 0) {
            digits[length] = (nbr % 10) * -1 + '0';
            nbr = nbr / 10;
            length++;
        }
    } else {
        while (nbr != 0) {
            digits[length] = nbr % 10 + '0';
            nbr = nbr / 10;
            length++;
        }
    }


    while (length > 0) {
        write(1, &digits[length - 1], 1);
        length--;
    }

    write(1, "\n", 1);
}

int main(void) {
    putnbr(1234567890);
    putnbr(0x7fffffff);
    putnbr(0x80000000);
    putnbr(0xffffffff);
    putnbr(0x00000000);
    putnbr(0x00000001);
    putnbr(42);
    putnbr(-42);
    return 0;
}