#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} Segment;

int cmp(const void *x, const void *y) {
    const Segment *s1 = (const Segment *)x;
    const Segment *s2 = (const Segment *)y;
    if (s1->b != s2->b)
        return s1->b - s2->b;
    return s1->a - s2->a;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1)
        return 0;
    Segment *seg = (Segment *)malloc((size_t)n * sizeof(Segment));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &seg[i].a, &seg[i].b);
    }

    qsort(seg, n, sizeof(Segment), cmp);

    int count = 0;
    int last_end = -1; // a_i >= 0 theo đề
    for (int i = 0; i < n; i++) {
        if (seg[i].a > last_end) { // nghiêm: không cho chạm tại điểm
            count++;
            last_end = seg[i].b;
        }
    }

    printf("%d\n", count);
    free(seg);
    return 0;
}
/*
Input
6
0 10
3 7
6 14
9 11
12 15
17 19

Output
4
*/