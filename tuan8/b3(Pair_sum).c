#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

long long count_pairs(int *a, int n, long long x) {
    int l = 0, r = n - 1;
    long long ans = 0;

    while (l < r) {
        if ((long long)a[l] + a[r] <= x) {
            ans += (r - l);  // tất cả cặp (l, l+1..r)
            l++;
        } else {
            r--;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), cmp);

    int q;
    scanf("%d", &q);

    while (q--) {
        long long x;
        scanf("%lld", &x);
        printf("%lld\n", count_pairs(a, n, x));
    }

    free(a);
    return 0;
}
