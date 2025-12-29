#include <stdio.h>
int arr[100001];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int i, j;
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int sum = 0, dem = 0;
    for (i = 0; i <= n - k; i++) {
        for (j = 0; j < k; j++) {
            sum += arr[i + j];
        }
        if (sum % 2 == 0)
            dem++;
        sum = 0;
    }
    printf("%d", dem);
    return 0;
}