#include <stdio.h>
int n;
int arr[50] = {0};
void solution() {
    int dem = 0;
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return;
}
int Check() {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j])
                return 0;
        }
    }
    return 1;
}
void Try(int k) {
    for (int i = 1; i <= n; i++) {
        arr[k] = i;
        if (k == n - 1) {
            if (Check()) {
                solution();
            }
        } else
            Try(k + 1);
    }
}

int main() {
    scanf("%d", &n);
    Try(0);
    return 0;
}
/*
Input
3
Output
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

*/