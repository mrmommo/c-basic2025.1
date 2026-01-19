#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int i, arr[n];
    int sum = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("%d", sum);
    return 0;
}
/*
Input
4
1 2 3 4
Output
10
*/