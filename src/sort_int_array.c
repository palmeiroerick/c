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

void merge(int *subarray, const int lenght) {
    // if (lenght == 2 && subarray[0] > subarray[1]) {
    //     swap(&subarray[0], &subarray[1]);
    // }

    int buffer[lenght];

    int i = 0;

    while (i < lenght) {
        buffer[i] = subarray[i];
        i++;
    }

    // i = 0; while (i < lenght) { putnbr(buffer[i]); i++; } write(1, "\n", 1);

    if (lenght == 4) {
        i = 0;
        int j = lenght / 2;
        int k = 0;

        while (k < lenght) {
            if (buffer[i] > buffer[j]) {
                subarray[k] = buffer[j];
                j++;
            } else {
                subarray[k] = buffer[i];
                i++;
            }
            k++;
        }
    }
}

void sort(int *array, const int size) {
    int subsize = 2;
    int i = 0;

    while (i < size) {
        merge(&array[i], subsize);
        i+=subsize;
    }

    i = 0;
    subsize = 4;
    
    while (i < size) {
        merge(&array[i], subsize);
        i+=subsize;
    }
}

int main(void) {
    int array[10] = {3, 7, 1, 2, 8, 9, 0, 6, 4, 5};
    int size = 10;

    sort(array, size);

    int i = 0;
    while (i < size) {
        putnbr(array[i]);
        i++;
    }

    return 0;
}