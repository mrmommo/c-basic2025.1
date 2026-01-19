#include <stdio.h>
#include <string.h>
char p1[50], p2[50], t[10001], ketqua[1001];
int main() {
    fgets(p1, 50, stdin);
    p1[strcspn(p1, "\n")] = '\0';
    fgets(p2, 50, stdin);
    p2[strcspn(p2, "\n")] = '\0';
    fgets(t, 1001, stdin);
    t[strcspn(t, "\n")] = '\0';
    int i = 0, post = 0;
    while (t[i] != '\0') {
        if (strncmp(&t[i], p1, strlen(p1)) == 0) {
            strcpy(&ketqua[post], p2);
            post += strlen(p2);
            i += strlen(p1);
        } else {
            ketqua[post] = t[i];
            i++;
            post++;
        }
    }
    for (int i = 0; i < strlen(ketqua); i++)
        printf("%c", ketqua[i]);
    return 0;
}
/*
Dữ liệu
· Dòng 1: xâu P1
· Dòng 2: xâu P2
· Dòng 3: văn bản T
Kết quả:
· Ghi văn bản T sau khi thay thế
Ví dụ
Dữ liệu
AI
Artificial Intelligence
Recently, AI is a key technology. AI enable efficient operations in many fields.
Kết quả
Recently, Artificial Intelligence is a key technology. Artificial Intelligence
enable efficient operations in many fields.
*/