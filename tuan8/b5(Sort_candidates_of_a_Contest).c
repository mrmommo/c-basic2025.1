#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char code[15];
    int score;
} Candidate;

int cmp(const void *a, const void *b) {
    Candidate *x = (Candidate *)a;
    Candidate *y = (Candidate *)b;
    return y->score - x->score;   // giảm dần
}

int main() {
    Candidate a[1000005];
    int n = 0;

    char code[15];
    int score;

    while (1) {
        if (scanf("%s", code) != 1) return 0;

        if (strcmp(code, "#") == 0) break;
        
        scanf("%d", &score);

        strcpy(a[n].code, code);
        a[n].score = score;
        n++;
    }

    qsort(a, n, sizeof(Candidate), cmp);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", a[i].code, a[i].score);
    }

    return 0;
}
