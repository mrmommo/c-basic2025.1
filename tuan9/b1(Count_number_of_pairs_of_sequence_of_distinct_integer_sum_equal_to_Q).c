#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, Q;
    scanf("%d %d", &n, &Q);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp);
    int left = 0, right = n - 1, count = 0;
    while (left < right) {
        if (a[left] + a[right] == Q) {
            count++;
            left++;
            right--;
        } else if (a[left] + a[right] < Q) {
            left++;
        } else {
            right--;
        }
    }
    printf("%d\n", count);
    free(a);
    return 0;
}
/*
Input
5 8
4 6 5 3 2
Output
2
*/