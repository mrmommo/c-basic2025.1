#include <stdio.h>
int n;
int arr[21];
void solution() {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}
void Try(int k) {
    for (int i = 0; i <= 1; i++) {
        arr[k] = i;
        if (k < n - 1)
            Try(k + 1);
        else if (k == n - 1)
            solution();
    }
}
int main() {
    scanf("%d", &n);
    Try(0);
    return 0;
}