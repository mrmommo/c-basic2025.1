#include <math.h>
#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    int i, arr[10000];
    int dem = 0;
    for (i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            arr[dem] = i;
            dem++;
            if (n / i != i) {
                arr[dem] = n / i;
                dem++;
            }
        }
    }
    for (i = 0; i < dem; i++) {
        for (int j = i + 1; j < dem; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    for (int i = 0; i < dem; i++)
        printf("%d ", -arr[i]);
    for (int i = dem - 1; i >= 0; i--)
        printf("%d ", arr[i]);
    return 0;
}