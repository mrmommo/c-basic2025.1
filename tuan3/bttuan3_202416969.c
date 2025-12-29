#include <stdio.h>
#include <stdlib.h>

// Hàm Alloc_Cub(m, r, c)

int ***Alloc_Cub(int m, int r, int c) {
    int i, j;
    int ***a = (int ***)malloc(m * sizeof(int **));
    if (!a)
        return NULL;

    for (i = 0; i < m; i++) {
        a[i] = (int **)malloc(r * sizeof(int *));
        if (!a[i])
            return NULL;
        for (j = 0; j < r; j++) {
            a[i][j] = (int *)calloc(c, sizeof(int));
            if (!a[i][j])
                return NULL;
        }
    }
    return a;
}

// Hàm Free_Cub(...)
void Free_Cub(int ***a, int m, int r) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < r; j++)
            free(a[i][j]);
        free(a[i]);
    }
    free(a);
}

//* Hàm Realloc_Cub(...)

void Realloc_Cub(int ****p, int m, int r, int c, int m2, int r2, int c2) {
    int ***old = *p;
    int ***new = Alloc_Cub(m2, r2, c2);
    if (!new)
        return;
    int mm = (m < m2 ? m : m2);
    int rr = (r < r2 ? r : r2);
    int cc = (c < c2 ? c : c2);
    for (int i = 0; i < mm; i++)
        for (int j = 0; j < rr; j++)
            for (int k = 0; k < cc; k++)
                new[i][j][k] = old[i][j][k];

    Free_Cub(old, m, r);
    *p = new;
}

int main() {
    int m = 2, r = 3, c = 4;
    int ***a = Alloc_Cub(m, r, c);
    if (!a)
        return 1;

    // Gán giá trị mẫu
    for (int i = 0; i < m; i++)
        for (int j = 0; j < r; j++)
            for (int k = 0; k < c; k++)
                a[i][j][k] = i + j + k;

    printf(" Trước khi cấp phát lại \n");
    for (int i = 0; i < m; i++) {
        printf("M%d:\n", i);
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++)
                printf("%3d ", a[i][j][k]);
            printf("\n");
        }
        printf("-----------------\n");
    }

    // Tái cấp phát mảng
    int m2 = 4, r2 = 4, c2 = 4;
    Realloc_Cub(&a, m, r, c, m2, r2, c2);

    printf("\n Sau khi cấp phát lại\n");
    for (int i = 0; i < m2; i++) {
        printf("M%d:\n", i);
        for (int j = 0; j < r2; j++) {
            for (int k = 0; k < c2; k++)
                printf("%3d ", a[i][j][k]);
            printf("\n");
        }
        printf("-----------------\n");
    }

    Free_Cub(a, m2, r2);
    return 0;
}
