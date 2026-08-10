#include <unistd.h>

// void combination(void) {
//     char n1 = '0';
//     char n2 = '1';
//     char n3 = '2';

//     while (n1 <= '7') {
//         while (n3 <= '9') {
//             write(1, &n1, 1);
//             write(1, &n2, 1);
//             write(1, &n3, 1);
//             if (n1 != '7' || n2 != '8' || n3 != '9')
//                 write(1, ", ", 2);
//             n3 += 1;
//         }
//         if (n2 == '9') {
//             n1 += 1;
//             n2 = n1 + 1;
//             n3 = n2 + 1;
//         } else {
//             n2 += 1;
//             n3 = n2 + 1;
//         }
//     }
// }

typedef struct {
    char n1;
    char n2;
    char n3;
} s_comb;

s_comb next_comb(s_comb comb) {
    if (comb.n3 == '9') {
        comb.n2++;
        comb.n3 = comb.n2 + 1;
    } else {
        comb.n3++;
    }
    if (comb.n2 == '9') {
        comb.n1++;
        comb.n2 = comb.n1 + 1;
        comb.n3 = comb.n2 + 1;
    } 
    return comb;
}

void comb(void) {
    s_comb comb = {'0', '1', '2'};

    while (1) {
        write(1, &comb.n1, 1);
        write(1, &comb.n2, 1);
        write(1, &comb.n3, 1);
        if (comb.n1 == '7') break;
        write(1, ", ", 2);
        comb = next_comb(comb);
    }
}

int main(void) {
    comb();
    return 0;
}