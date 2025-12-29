#include <math.h>
#include <stdio.h>

int arr[1000001];
int main() {
    int n;
    scanf("%d", &n);
    int i, dem = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (sqrt(arr[i]) == (int)sqrt(arr[i]))
            dem++;
    }
    printf("%d", dem);
    return 0;
}