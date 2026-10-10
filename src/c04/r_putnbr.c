#include <unistd.h>

void r_putnbr(int num) {
    char s_num[11] = "";
    size_t s_size = 0;
    int divisor = 1;
        
    if (num < 0) s_num[s_size++] = '-';
    if (num > 0) num = -num; 

    while (num / divisor <= -10) divisor *= 10;

    while (divisor > 0) {
        s_num[s_size++] = '0' - num / divisor % 10;
        divisor /= 10;
    }

    write(1, s_num, s_size);
}

int main(void) {
    r_putnbr(0x7fffffff);
    write(1, "\n", 1);
    r_putnbr(0x80000000);
    write(1, "\n", 1);
    r_putnbr(0xffffffff);
    write(1, "\n", 1);
    r_putnbr(0x00000000);
    write(1, "\n", 1);
    r_putnbr(0x00000045);
    write(1, "\n", 1);
    return 0;
}
