#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int X[n + 1], Y[m + 1];
    for (int i = 1; i <= n; i++)
        scanf("%d", &X[i]);
    for (int j = 1; j <= m; j++)
        scanf("%d", &Y[j]);

    static int dp[10001][10001]; // dùng static để lưu trên vùng nhớ toàn cục

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[i] == Y[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    printf("%d", dp[n][m]);
    return 0;
}
/*
Input
7 10
3 7 2 5 1 4 9
4 3 2 3 6 1 5 4 9 7
Output
5
*/