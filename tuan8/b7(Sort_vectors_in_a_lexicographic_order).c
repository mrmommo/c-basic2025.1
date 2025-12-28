#include <stdio.h>
#include <stdlib.h>

int n, m;
int a[100000][10];

int cmp(const void *x, const void *y) {
    const int *v1 = (const int *)x;
    const int *v2 = (const int *)y;

    for (int i = 0; i < m; i++) {
        if (v1[i] < v2[i]) return -1;
        if (v1[i] > v2[i]) return 1;
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    qsort(a, n, sizeof(a[0]), cmp);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}
