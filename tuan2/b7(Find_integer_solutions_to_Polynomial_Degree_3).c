#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#define MAX_ROOTS 3

long long cubic(int a, int b, int c, int x) {
    return (long long)x * x * x + (long long)a * x * x + (long long)b * x + c;
}

int find_divisors(int c, int divisors[]) {
    int count = 0;
    int abs_c = abs(c);
    for (int i = 1; i * i <= abs_c; ++i) {
        if (abs_c % i == 0) {
            divisors[count++] = i;
            if (i != abs_c / i)
                divisors[count++] = abs_c / i;
        }
    }
    if (c < 0) {
        int orig = count;
        for (int i = 0; i < orig; ++i)
            divisors[count++] = -divisors[i];
    }
    return count;
}

int main() {
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("NO SOLUTION\n");
        return 0;
    }
    int roots[MAX_ROOTS], mult[MAX_ROOTS], nroots = 0;
    int ca = a, cb = b, cc = c;
    int found = 0;
    int divisors[10000], dcount = 0;
    // Find all divisors of c (including negative)
    int abs_c = abs(c);
    for (int i = 1; i * (long long)i <= abs_c; ++i) {
        if (abs_c % i == 0) {
            divisors[dcount++] = i;
            if (i != abs_c / i)
                divisors[dcount++] = abs_c / i;
        }
    }
    for (int i = 0, orig = dcount; i < orig; ++i)
        divisors[dcount++] = -divisors[i];

    for (int k = 0; k < MAX_ROOTS; ++k) {
        int root = 0, multiplicity = 0;
        int found_root = 0;
        for (int i = 0; i < dcount; ++i) {
            int x = divisors[i];
            // Skip already used roots
            int skip = 0;
            for (int t = 0; t < nroots; ++t)
                if (roots[t] == x)
                    skip = 1;
            if (skip)
                continue;
            long long val =
                (k == 0)   ? ((long long)x * x * x + (long long)ca * x * x +
                            (long long)cb * x + cc)
                : (k == 1) ? ((long long)x * x + (long long)ca * x + cb)
                           : ((long long)x + ca);
            if (val == 0) {
                root = x;
                found_root = 1;
                break;
            }
        }
        if (!found_root)
            break;
        // Count multiplicity
        do {
            multiplicity++;
            if (k == 0) {
                int na = ca + root;
                int nb = cb + na * root;
                ca = na;
                cb = nb;
                cc = 0;
            } else if (k == 1) {
                int na = ca + root;
                ca = na;
                cb = 0;
            } else {
                ca = 0;
            }
            long long val =
                (k == 0)
                    ? ((long long)root * root * root +
                       (long long)ca * root * root + (long long)cb * root + cc)
                : (k == 1)
                    ? ((long long)root * root + (long long)ca * root + cb)
                    : ((long long)root + ca);
            if (val != 0)
                break;
        } while (multiplicity < 3);
        roots[nroots] = root;
        mult[nroots] = multiplicity;
        nroots++;
        found = 1;
    }
    int ok = 0;
    if (nroots == 3 && ca == 0 && cb == 0 && cc == 0)
        ok = 1;
    if (nroots == 2 && ca == 0 && cb == 0)
        ok = 1;
    if (nroots == 1 && ca == 0)
        ok = 1;
    if (!ok) {
        printf("NO SOLUTION\n");
        return 0;
    }
    for (int i = 0; i < nroots - 1; ++i)
        for (int j = i + 1; j < nroots; ++j)
            if (roots[i] > roots[j]) {
                int t = roots[i];
                roots[i] = roots[j];
                roots[j] = t;
                t = mult[i];
                mult[i] = mult[j];
                mult[j] = t;
            }
    for (int i = 0; i < nroots; ++i)
        printf("%d %d\n", roots[i], mult[i]);
    return 0;
}
/*
Input
-1  -1  -2
Output
NO SOLUTION

Input
-6 11 -6
Output
1 1
2 1
3 1

Input
8  5  -50
Output
-5  2
2   1
*/