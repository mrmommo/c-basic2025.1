#include <stdio.h>

int check_row(int mat[9][9], int row) {
    int seen[10] = {0};
    for (int j = 0; j < 9; ++j) {
        int val = mat[row][j];
        if (val < 1 || val > 9 || seen[val])
            return 0;
        seen[val] = 1;
    }
    return 1;
}

int check_col(int mat[9][9], int col) {
    int seen[10] = {0};
    for (int i = 0; i < 9; ++i) {
        int val = mat[i][col];
        if (val < 1 || val > 9 || seen[val])
            return 0;
        seen[val] = 1;
    }
    return 1;
}

int check_square(int mat[9][9], int start_row, int start_col) {
    int seen[10] = {0};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            int val = mat[start_row + i][start_col + j];
            if (val < 1 || val > 9 || seen[val])
                return 0;
            seen[val] = 1;
        }
    return 1;
}

int is_sudoku(int mat[9][9]) {
    for (int i = 0; i < 9; ++i)
        if (!check_row(mat, i) || !check_col(mat, i))
            return 0;
    for (int i = 0; i < 9; i += 3)
        for (int j = 0; j < 9; j += 3)
            if (!check_square(mat, i, j))
                return 0;
    return 1;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        int mat[9][9];
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                scanf("%d", &mat[i][j]);
        printf("%d\n", is_sudoku(mat));
    }
    return 0;
}
/*
Input
2
1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 1 4 3 6 5 8 9 7
3 6 5 8 9 7 2 1 4
8 9 7 2 1 4 3 6 5
5 3 1 6 7 8 9 4 2
9 7 2 5 4 1 6 3 8
6 4 8 9 3 2 5 7 1
1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 1 4 3 6 5 8 9 7
3 6 5 8 9 7 2 1 4
8 9 7 2 1 4 3 6 5
5 3 1 6 7 8 9 4 2
9 7 8 5 4 2 6 3 1
4 4 2 9 3 1 5 7 8

Output
1
0
*/