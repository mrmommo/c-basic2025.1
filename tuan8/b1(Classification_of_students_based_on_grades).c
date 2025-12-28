#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[11];
    int grade;
    int position;
} Student;

int compareGrade(const void* a, const void* b) {
    return ((Student*)a)->grade - ((Student*)b)->grade;
}

int compareID(const void* a, const void* b) {
    return strcmp(((Student*)a)->id, ((Student*)b)->id);
}

int main() {
    int n;
    scanf("%d", &n);

    Student* students = (Student*)malloc(n * sizeof(Student));

    for (int i = 0; i < n; i++) {
        scanf("%s %d", students[i].id, &students[i].grade);
    }

    // Sắp xếp theo điểm để gán vị trí
    qsort(students, n, sizeof(Student), compareGrade);
    for (int i = 0; i < n; i++) {
        students[i].position = i;
    }

    // Sắp xếp lại theo ID để in ra đúng thứ tự
    qsort(students, n, sizeof(Student), compareID);
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", students[i].id, students[i].position);
    }

    free(students);
    return 0;
}
