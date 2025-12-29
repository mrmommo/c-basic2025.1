#include <limits.h>
#include <stdio.h>

int mindis = INT_MAX;
int n, dis = 0;
int arrdis[105][105];
int last[105];
int visited[105] = {0};
void Try(int i) {
    for (int j = 1; j < n; j++) {
        if (visited[j] == 0) {
            visited[j] = 1;
            last[i] = j;
            dis += arrdis[last[i - 1]][last[i]];
            if (dis > mindis) {
                visited[j] = 0;
                dis -= arrdis[last[i - 1]][last[i]];
                continue;
            }
            if (i < n - 1)
                Try(i + 1);
            else if (i == n - 1) {
                if (mindis > dis + arrdis[last[n - 1]][last[0]])
                    mindis = dis + arrdis[last[n - 1]][last[0]];
            }
        } else
            continue;
        visited[j] = 0;
        dis -= arrdis[last[i - 1]][last[i]];
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arrdis[i][j]);
        }
    }
    visited[0] = 1;
    Try(1);
    printf("%d", mindis);
    return 0;
}