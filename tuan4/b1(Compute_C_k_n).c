#include <stdio.h>
long long arr[1000][1000] = {0};
long long Ckn(int k, int n) {
    if (k == 0 || k == n)
        return 1;
    else if (k == 1)
        return n;
    if (arr[k][n] != 0)
        return arr[k][n] % 1000000007;
    arr[k][n] = (Ckn(k - 1, n - 1) + Ckn(k, n - 1)) % 1000000007;
    return arr[k][n];
}
int main() {
    int k, n;
    scanf("%d %d", &k, &n);
    printf("%lld", Ckn(k, n));
    return 0;
}