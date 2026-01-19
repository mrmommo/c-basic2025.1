#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// sort
static void merge(char *base, char *temp, size_t left, size_t mid, size_t right,
                  size_t size, int (*compare)(const void *, const void *)) {
    size_t i = left, j = mid, k = left;

    while (i < mid && j < right) {
        if (compare(base + i * size, base + j * size) <= 0) {
            memcpy(temp + k * size, base + i * size, size);
            i++;
        } else {
            memcpy(temp + k * size, base + j * size, size);
            j++;
        }
        k++;
    }

    while (i < mid) {
        memcpy(temp + k * size, base + i * size, size);
        i++;
        k++;
    }

    while (j < right) {
        memcpy(temp + k * size, base + j * size, size);
        j++;
        k++;
    }

    for (i = left; i < right; i++) {
        memcpy(base + i * size, temp + i * size, size);
    }
}

static void mergesort_rec(char *base, char *temp, size_t left, size_t right,
                          size_t size,
                          int (*compare)(const void *, const void *)) {
    if (right - left <= 1)
        return;

    size_t mid = (left + right) / 2;

    mergesort_rec(base, temp, left, mid, size, compare);
    mergesort_rec(base, temp, mid, right, size, compare);
    merge(base, temp, left, mid, right, size, compare);
}

void mergesort(void *base, size_t nitems, size_t size,
               int (*compare)(const void *, const void *)) {
    if (nitems < 2)
        return;

    char *temp = malloc(nitems * size);
    if (!temp)
        return;

    mergesort_rec((char *)base, temp, 0, nitems, size, compare);

    free(temp);
}
//
typedef struct {
    int id;
    char email[21];
} data;
int compare(const void *a, const void *b) {
    const data *x = (const data *)a;
    const data *y = (const data *)b;
    return strcmp(x->email, y->email);
}
int main() {
    int n;
    scanf("%d", &n);
    data sv[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &sv[i].id, sv[i].email);
    }
    mergesort(sv, n, sizeof(data), compare);
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", sv[i].id, sv[i].email);
    }
    return 0;
}