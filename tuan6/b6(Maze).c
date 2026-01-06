#include <stdio.h>
#define max 1000
int maze[max][max];
int n, m, r, c;
int visited[max][max] = {0};
// isBorder
int isBorder(int x, int y) {
    return x == 0 || y == 0 || x == n - 1 || y == m - 1;
}
// bfs
typedef struct {
    int x;
    int y;
    int step;
} node;
node queue[max * max];
int front = 0, rear = 0;
int dx[] = {0, 0, 1, -1}; // xuống , lên , phải , trái
int dy[] = {1, -1, 0, 0};
int bfs(int start_x, int start_y) {
    front = 0, rear = 0;
    queue[rear++] = (node){start_x, start_y, 0};
    visited[start_x][start_y] = 1;
    while (front < rear) {
        node curr = queue[front++];
        if (isBorder(curr.x, curr.y))
            return curr.step;
        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] &&
                maze[nx][ny] == 0) {
                visited[nx][ny] = 1;
                queue[rear++] = (node){nx, ny, curr.step + 1};
            }
        }
    }

    return -1;
}
// Ghi giá số bước cần di chuyển ngắn nhất để thoát ra khỏi mê cung,
// hoặc ghi giá trị -1 nếu không tìm thấy đường đi nào thoát ra khỏi mê cung.
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //
    scanf("%d %d %d %d", &n, &m, &r, &c);
    r--, c--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    int result = bfs(r, c);
    printf("%d", result == -1 ? result : result + 1);
    return 0;
}