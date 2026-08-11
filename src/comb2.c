#include <unistd.h>

// typedef struct {
//     char n1;
//     char n2;
//     char m1;
//     char m2;
// } s_comb;

// void comb2(void) {
//     s_comb comb = { '0', '0', '0', '1' };

//     while (comb.n1 <= '9' && comb.n2 <= '9') {
//         while (comb.m1 <= '9' && comb.m2 <= '9') {
//             write(1, &comb.n1, 1);
//             write(1, &comb.n2, 1);
//             write(1, " ", 1);
//             write(1, &comb.m1, 1);
//             write(1, &comb.m2, 1);
//             write(1, ", ", 2);

//             if (comb.m2 == '9') {
//                 comb.m1++;
//                 comb.m2 = '0';
//             } else {
//                 comb.m2++;
//             }
//         }

//         if (comb.n2 == '9') {
//             comb.n1++;
//             comb.n2 = '0';
//         } else {
//             comb.n2++;
//         }

//         comb.m1 = comb.n1;
//         comb.m2 = comb.n2 + 1;
//     }
// }

/* Mathematical View: 
    S = {(a, b) ∣ 0 ≤ a < b ≤ 99}

    next(a, b) = {
        (a, b + 1) if b < 99
        (a + 1, a + 2) if b = 99 and a < 98
    } 
*/

typedef struct {
    int a;
    int b;
} s_comb;

s_comb next_comb(s_comb comb) {
    if (comb.b == 99) {
        comb.a++;
        comb.b = comb.a + 1;
    } else {
        comb.b++;
    }
    return comb;
}

void print_comb(s_comb comb) {
    char str[5];
    str[0] = comb.a / 10 + '0';
    str[1] = comb.a % 10 + '0';
    str[2] = ' ';
    str[3] = comb.b / 10 + '0';
    str[4] = comb.b % 10 + '0';
    write(1, str, 5);
}

void comb2(void) {
    s_comb comb = {0, 1};

    // Print first combination without ", ", then the loop prints ", "
    // between each combination, not printing after the last one.
    print_comb(comb);
    comb = next_comb(comb);

    while (comb.a < comb.b && comb.b <= 99) {
        write(1, ", ", 2);
        print_comb(comb);
        comb = next_comb(comb);
    }
}

int main(void) {
    comb2();
    return 0;
}