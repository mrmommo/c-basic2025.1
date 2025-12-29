#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int arr[13][13] = {0};
int n;
int dem = 0;
int Check(int r, int c) {
    for (int i = 0; i < n; i++) {
        if (i != c && arr[r][i] == 1)
            return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i != r && arr[i][c] == 1)
            return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) {
                if (i == r && j == c)
                    continue;
                if (abs(i - r) == abs(j - c))
                    return 0;
            }
        }
    }

    return 1;
}

void TryRow(int r) {
    if (r == n) {
        dem++;
        return;
    }

    int preset_col = -1;
    for (int j = 0; j < n; ++j) {
        if (arr[r][j] == 1) {
            preset_col = j;
            break;
        }
    }
    if (preset_col != -1) {
        if (Check(r, preset_col))
            TryRow(r + 1);
        return;
    }
    for (int j = 0; j < n; ++j) {
        if (Check(r, j)) {
            arr[r][j] = 1;
            TryRow(r + 1);
            arr[r][j] = 0;
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == 1) {
                if (!Check(i, j)) {
                    printf("0");
                    return 0;
                }
            }
        }
    }

    TryRow(0);
    printf("%d", dem);
    return 0;
}
