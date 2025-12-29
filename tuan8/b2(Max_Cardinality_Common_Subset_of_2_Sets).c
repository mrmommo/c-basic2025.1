#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *A = (int *)malloc(n * sizeof(int));
    int *B = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for (int j = 0; j < m; j++)
        scanf("%d", &B[j]);
    qsort(B, m, sizeof(int), cmp);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (bsearch(&A[i], B, m, sizeof(int), cmp) != NULL) {
            count++;
        }
    }

    printf("%d\n", count);

    free(A);
    free(B);
    return 0;
}
