#include <stdio.h>
int Qcheck(int arr[][101], int NxN) {
    int i, j;
    for (i = 0; i < NxN; i++) {
        for (j = 0; j < NxN; j++) {
            if (arr[i][j] == 1) {
                int m, n;
                for (m = i + 1, n = j - 1; m < NxN && n >= 0; m++, n--)
                    if (arr[m][n] == 1)
                        return 0;
                for (m = i + 1, n = j + 1; m < NxN && n < NxN; m++, n++)
                    if (arr[m][n] == 1)
                        return 0;
                for (m = i + 1, n = j; m < NxN; m++)
                    if (arr[m][n] == 1)
                        return 0;
                for (m = i, n = j + 1; n < NxN; n++)
                    if (arr[m][n] == 1)
                        return 0;
            }
        }
    }
    return 1;
}

int kq[100];
int arr[101][101] = {0};
int main() {
    int num;
    scanf("%d", &num);
    int i, j, k;
    for (i = 0; i < num; i++) {
        int NxN;
        scanf("%d", &NxN);
        for (j = 0; j < NxN; j++) {
            for (k = 0; k < NxN; k++) {
                scanf("%d", &arr[j][k]);
            }
        }
        kq[i] = Qcheck(arr, NxN);
    }
    for (i = 0; i < num; i++)
        printf("%d\n", kq[i]);
    return 0;
}