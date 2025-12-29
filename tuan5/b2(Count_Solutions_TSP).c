#include <limits.h>
#include <stdio.h>

int n, maxdis;
int arr[101][101];
int dis = 0;
int dem = 0;
int C[101]; // tp di qua
int visited[101] = {0};
void Try(int i) {
    for (int j = 1; j < n; j++) {
        if (visited[j] == 0) {
            visited[j] = 1;
            C[i] = j;
            dis += arr[C[i - 1]][C[i]];
            if (i < n - 1)
                Try(i + 1);
            else if (i == n - 1) {
                if (maxdis - dis - arr[C[n - 1]][C[0]] >= 0)
                    dem++;
            }
        } else
            continue;
        visited[j] = 0;
        dis -= arr[C[i - 1]][C[i]];
    }
}
int main() {
    scanf("%d %d", &n, &maxdis);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    visited[0] = 1;
    Try(1);
    printf("%d", dem);
    return 0;
}