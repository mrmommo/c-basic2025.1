#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[11];
    int grade;
    int position;
} Student;

int compareGrade(const void *a, const void *b) {
    return ((Student *)a)->grade - ((Student *)b)->grade;
}

int compareID(const void *a, const void *b) {
    return strcmp(((Student *)a)->id, ((Student *)b)->id);
}

int main() {
    int n;
    scanf("%d", &n);

    Student *students = (Student *)malloc(n * sizeof(Student));

    for (int i = 0; i < n; i++) {
        scanf("%s %d", students[i].id, &students[i].grade);
    }
    qsort(students, n, sizeof(Student), compareGrade);
    for (int i = 0; i < n; i++) {
        students[i].position = i;
    }
    qsort(students, n, sizeof(Student), compareID);
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", students[i].id, students[i].position);
    }

    free(students);
    return 0;
}
/*
Input
5
S000003 3
S000002 6
S000005 5
S000004 10
S000001 8

Output
S000001 3
S000002 2
S000003 0
S000004 4
S000005 1
*/