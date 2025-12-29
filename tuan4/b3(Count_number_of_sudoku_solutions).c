#include <stdio.h>
int arr[10][10];
int dem = 0;
int Check(int m, int n) {
    for (int i = 0; i < 9; i++) {
        if (arr[m][n] == arr[i][n] && arr[m][n] != 0 && i != m)
            return 0;
    }
    for (int i = 0; i < 9; i++) {
        if (arr[m][n] == arr[m][i] && arr[m][n] != 0 && i != n)
            return 0;
    }
    for (int i = m / 3 * 3; i < m / 3 * 3 + 3; i++) {
        for (int j = n / 3 * 3; j < n / 3 * 3 + 3; j++) {
            if (arr[m][n] == arr[i][j] && arr[m][n] != 0 && (m != i || n != j))
                return 0;
        }
    }
    return 1;
}
void Try(int k1, int k2) {
    if (arr[k1][k2] == 0) {
        for (int i = 1; i <= 9; i++) {
            arr[k1][k2] = i;
            if (Check(k1, k2)) {
                if (k1 == 8 && k2 == 8)
                    dem++;
                else if (k2 == 8)
                    Try(k1 + 1, 0);
                else if (k2 < 8)
                    Try(k1, k2 + 1);
            }
            arr[k1][k2] = 0;
        }
    } else if (arr[k1][k2] != 0) {
        if (Check(k1, k2)) {
            if (k1 == k2 && k1 == 8)
                dem++;
            else if (k2 == 8)
                Try(k1 + 1, 0);
            else if (k2 < 8)
                Try(k1, k2 + 1);
        }
    }
}
int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    Try(0, 0);
    printf("%d", dem);
    return 0;
}
