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

int min(int x, int y) {
    if (x < y)
        return x;
    return y;
}

void merge(int *subarray, int start, int mid, int end) {
    int i, j, k;
    int buffer[end + 1];

    i = 0;

    while (i <= end) {
        buffer[i] = subarray[i];
        i++;
    }

    i = start;
    j = mid + 1;
    k = start;

    while (i <= mid && j <= end) {
        if (buffer[i] > buffer[j]) {
            subarray[k] = buffer[j];
            j++;
        } else {
            subarray[k] = buffer[i];
            i++;
        }
        k++;
    }

    while (i <= mid) {
        subarray[k] = buffer[i];
        k++;
        i++;
    }

    while (j <= end) {
        subarray[k] = buffer[j];
        k++;
        j++;
    }
}

void sort(int *array, const int size) {
    int subsize;
    int start;
    int mid;
    int end;

    subsize = 1;
    while (subsize < size) {
        start = 0;
        while (start < size) {
            mid = min(start + subsize - 1, size - 1);
            end = min(start + 2*subsize - 1, size - 1);
            if (mid < end) {
                merge(array, start, mid, end);
            }
            start+=2*subsize;
        }
        subsize*=2;
    }
}

int main(void) {
    int array[10] = {7, 3, 2, 1, 6, 9, 0, 8, 4, 5};
    int size = 10;

    sort(array, size);

    int i = 0;
    while (i < size) {
        putnbr(array[i]);
        write(1, ", ", 2);
        i++;
    }

    return 0;
}