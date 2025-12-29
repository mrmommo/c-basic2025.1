#include <stdio.h>
int a[101][101], b[101][101], c[101][101] = {0};
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int k1, m;
    scanf("%d %d", &k1, &m);
    for (i = 0; i < k; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (int h = 0; h < k; h++) {
                c[i][j] += a[i][h] * b[h][j];
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}