#include <stdio.h>
int ma[1001][1001];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &ma[i][j]);
        }
    }
    int dem = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (ma[j][i] != 1)
                break;
            if (j == n - 1)
                dem++;
        }
    }
    printf("%d", dem);
    return 0;
}