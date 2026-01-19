#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 901

typedef struct {
    int a, b, steps;
} State;

int visited[MAX][MAX];

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int minSteps(int a, int b, int c) {
    if (c > a && c > b)
        return -1;
    if (c % gcd(a, b) != 0)
        return -1;

    memset(visited, 0, sizeof(visited));
    State queue[MAX * MAX];
    int front = 0, rear = 0;

    queue[rear++] = (State){0, 0, 0};

    while (front < rear) {
        State curr = queue[front++];
        int x = curr.a, y = curr.b;

        if (x == c || y == c)
            return curr.steps;
        if (visited[x][y])
            continue;
        visited[x][y] = 1;

        queue[rear++] = (State){a, y, curr.steps + 1};
        queue[rear++] = (State){x, b, curr.steps + 1};
        queue[rear++] = (State){0, y, curr.steps + 1};
        queue[rear++] = (State){x, 0, curr.steps + 1};
        int pour = (x < b - y) ? x : (b - y);
        queue[rear++] = (State){x - pour, y + pour, curr.steps + 1};
        pour = (y < a - x) ? y : (a - x);
        queue[rear++] = (State){x + pour, y - pour, curr.steps + 1};
    }

    return -1;
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", minSteps(a, b, c));
    return 0;
}
/*
Input
6  8  4
Output
4
*/