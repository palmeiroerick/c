#include "libc.h"

#define N 4 // 0, 1, 2, 3 

typedef struct {
    int line;
    int column;
} coord_t;

int possibilities = 0;
char solution[N + 1] = "";

// Covering Arrays
int occupied_line[N] = {0};
int occupied_column[N] = {0};
int occupied_diagonal_1[2 * N - 1] = {0};
int occupied_diagonal_2[2 * N - 1] = {0};

// # # # # 0
// # # # # 1
// # # # # 2
// # # # # 3
// 0 1 2 3

// I did this function just to discover `column - line = constant`, funny.
// int get_diagonal(coord_t coord) {
//     // 0x0 -> 3, 1x1 -> 3, 2x2 -> 3, 3x3 -> 3.
//     if (coord.line == coord.column) return N - 1;

//     // 0x1 -> 4, 1x2 -> 4, 2x3 -> 4.
//     // 0x2 -> 5, 1x3 -> 5. 0x3 -> 6.
//     if (coord.line < coord.column) return (N - 1) + coord.column - coord.line;

//     // 1x0 -> 2, 2x1 -> 2, 3x2 -> 2.
//     // 2x0 -> 1, 3x1 -> 1. 3x0 -> 0.
//     if (coord.line > coord.column) return (N - 1) + coord.column - coord.line;
// } 

int valid_coord(coord_t coord) {
    return !occupied_line[coord.line]
        && !occupied_column[coord.column]
        && !occupied_diagonal_1[N - 1 + coord.column - coord.line]
        && !occupied_diagonal_2[coord.column + coord.line];
}

// int four_queen(int line) {
    // I need some way of couting the amount of possibilities
    // I need to track the deepth
    // I need it recursive call to know in which column it is.
    // [maybe no, maybe this problem wants me to also verify the line
    // because the line is the deepth, I could discart completely the
    // line verification if in it call a move one line down.]
    // coord_t coord = { .line = line, .column = 1; };

    // if (line < N - 1) {
    // }

    // if (line == N - 1) {
    //     c_putstr(solution);
    //     possibilities += 1;
    //     return 0;
    // }

    // return possibilities;
// }

int main(void) {
    four_queen(0);
    return 0;
}