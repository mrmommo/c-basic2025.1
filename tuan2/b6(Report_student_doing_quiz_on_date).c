
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 50000

typedef struct {
    char date[11];
    int count;
} DayCount;

int cmp_daycount(const void *a, const void *b) {
    return strcmp(((const DayCount *)a)->date, ((const DayCount *)b)->date);
}

int main() {
    char line[256];
    DayCount days[MAX];
    int n = 0;

    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '*')
            break;
        char date[11];
        sscanf(line, "%10s", date);
        int found = 0;
        for (int i = 0; i < n; ++i) {
            if (strcmp(days[i].date, date) == 0) {
                days[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(days[n].date, date);
            days[n].count = 1;
            n++;
        }
    }

    qsort(days, n, sizeof(DayCount), cmp_daycount);

    for (int i = 0; i < n; ++i) {
        printf("%s %d\n", days[i].date, days[i].count);
    }
    return 0;
}
/*
Input
2022-01-02 10:30:24 dungpq question1
2022-01-03 11:30:24 dungpq question1
2022-02-01 03:30:20 viettq question2
2022-02-01 03:35:20 viettq question1
2022-03-01 03:30:20 viettq question7
2022-01-02 11:20:24 viettq question2
*
Output
2022-01-02 2
2022-01-03 1
2022-02-01 2
2022-03-01 1
*/
