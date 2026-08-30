#include <unistd.h>

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

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void rev_int_array(int *array, int size) {
    int *left = array;
    int *right = array + size - 1;

    while (left < right) {
        swap(left, right);
        left++;
        right--;
    }
}

int main(void) {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = 10;

    rev_int_array(array, size);

    int i = 0;
    while (i < size) {
        putnbr(array[i]);
        i++;
    }

    return 0;
}