#include <stdio.h>
int arr[101] = {0};
int a, b;
int dem = 0;
int sum = 0;
int Try(int k) {
    for (int i = 0; i <= 1; i++) {
        if (i == 1)
            sum += arr[k];
        if (sum > b) {
            sum -= arr[k];
            continue;
        }
        if (k == a - 1) {
            if (sum == b)
                dem++;
            if (i == 1)
                sum -= arr[k];
        }

        else {
            Try(k + 1);
            if (i == 1)
                sum -= arr[k];
        }
    }
}
int main() {
    scanf("%d %d", &a, &b);
    for (int i = 0; i < a; i++)
        scanf("%d", &arr[i]);
    Try(0);
    printf("%d", dem);
    return 0;
}
/*
Input
5 6
1 2 3 4 5
Output
3
*/