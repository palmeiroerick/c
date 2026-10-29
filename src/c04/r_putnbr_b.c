#include "libc.h"

int get_radix(char *base) {
    size_t len = 0;
    int seen[256] = {0};
    unsigned char c;

    while (*base) {
        c = (unsigned char) *base++;
        if (c == '+' || c == '-' || seen[c]) return 0;
        seen[c] = 1; len++;
    }

    return len >= 2 ? len : 0;
}

void r_putnbr_b(int num, char *base) {
    int radix = get_radix(base);
    if (!radix) return;

    if (num == 0) {
        c_putchar(base[0]);
        return;
    }

    // If radix is 2 (the least possible) we need 66 [sign + 64 + '\0'] chars to
    // represent an integers. Any other radix will need less characters.
    // TODO: There is probably a clever way to calculate it.
    char output[66] = "";
    char *ptr = output + 66 - 1;
    *ptr-- = '\0';

    int is_negative = num < 0;
    
    if (num > 0) num = -num;

    while (num < 0) {
        *ptr-- = base[-(num % radix)];
        num /= radix;
    }

    if (is_negative) { *ptr-- = '-'; }

    c_putstr(ptr + 1);
}

int main(void) {
    char *hex_b = "0123456789abcdef";
    r_putnbr_b(0xeaea, hex_b);
    c_putchar('\n');
    r_putnbr_b(-0xeaea, hex_b);
    c_putchar('\n');
    r_putnbr_b(0x7fffffff, hex_b);
    c_putchar('\n');
    r_putnbr_b(0x80000000, hex_b);
    c_putchar('\n');
    r_putnbr_b(0xffffffff, hex_b);
    c_putchar('\n');
    r_putnbr_b(0x00000000, hex_b);
    c_putchar('\n');
    r_putnbr_b(0x00000045, hex_b);
    return 0;
}