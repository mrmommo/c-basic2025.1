#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node
typedef struct TERM {
    int coef;
    int exp;
    struct TERM *next;

} term;
// head
term *polys[10001] = {NULL};
//
void create(int id) {
    if (polys[id] == NULL)
        polys[id] = NULL;
}
// addterm exp so mu theo thu tu
void addterm(int id, int coef, int exp) {
    if (!coef)
        return;
    create(id);
    term *cur = polys[id], *prev = NULL;
    while (cur && cur->exp > exp) {
        prev = cur;
        cur = cur->next;
    }
    // có sẵn exp
    if (cur && cur->exp == exp) {
        cur->coef += coef;
        // coef = 0
        if (cur->coef == 0) {
            if (prev)
                prev->next = cur->next;
            else
                polys[id] = cur->next;
            free(cur);
        }
    }
    // chưa có exp
    else {
        term *newterm = (term *)malloc(sizeof(term));
        newterm->coef = coef;
        newterm->exp = exp;
        newterm->next = cur;
        if (prev)
            prev->next = newterm;
        else
            polys[id] = newterm;
    }
}
// tính ,in
void evaluatepoly(int id, int x) {
    int sum = 0;
    term *cur = polys[id];
    if (!cur) {
        printf("0\n");
        return;
    } else {
        while (cur) {
            sum += (cur->coef) * (int)pow(x, cur->exp);
            cur = cur->next;
        }
    }
    printf("%d\n", sum);
}
// destroy
void destroy(int id) {
    term *cur = polys[id];
    while (cur) {
        term *temp = cur;
        cur = cur->next;
        free(temp);
    }
    polys[id] = NULL;
}
// add poly cộng hàm đa thức
void addpoly(int id1, int id2, int result_id) {
    term *cur1 = polys[id1], *cur2 = polys[id2];
    if (cur1 == NULL && cur2 == NULL)
        return;
    destroy(result_id);
    polys[result_id] = NULL;
    while (cur1 && cur2) {
        // addterm(int id, int coef, int exp)
        if (cur1->exp == cur2->exp) {
            addterm(result_id, cur1->coef + cur2->coef, cur1->exp);
            cur1 = cur1->next;
            cur2 = cur2->next;
        } else if (cur1->exp > cur2->exp) {
            addterm(result_id, cur1->coef, cur1->exp);
            cur1 = cur1->next;

        } else if (cur2->exp > cur1->exp) {
            addterm(result_id, cur2->coef, cur2->exp);
            cur2 = cur2->next;
        }
    }
    while (cur1) {
        addterm(result_id, cur1->coef, cur1->exp);
        cur1 = cur1->next;
    }
    while (cur2) {
        addterm(result_id, cur2->coef, cur2->exp);
        cur2 = cur2->next;
    }
}
// print poly
void printpoly(int id) {
    if (!polys[id])
        return;
    term *cur = polys[id];
    while (cur) {
        printf("%d %d", cur->coef, cur->exp);
        cur = cur->next;
        if (cur)
            printf(" ");
    }
    printf("\n");
}
int main() {
    char line[50];
    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == '*')
            return 0;
        if (!strncmp(line, "Create", 6)) {
            int v;
            sscanf(line + 7, "%d", &v);
            create(v);
        } else if (!strncmp(line, "AddTerm", 7)) {
            int id, coef, exp;
            sscanf(line + 8, "%d %d %d", &id, &coef, &exp);
            addterm(id, coef, exp);
        } else if (!strncmp(line, "Destroy", 7)) {
            int id;
            sscanf(line + 8, "%d", &id);
            destroy(id);
        } else if (!strncmp(line, "AddPoly", 7)) {
            int id1, id2, result_id;
            sscanf(line + 8, "%d %d %d", &id1, &id2, &result_id);
            addpoly(id1, id2, result_id);
        } else if (!strncmp(line, "PrintPoly", 9)) {
            int id;
            sscanf(line + 10, "%d", &id);
            printpoly(id);
        } else if (!strncmp(line, "EvaluatePoly", 12)) {
            int id, x;
            sscanf(line + 13, "%d %d", &id, &x);
            evaluatepoly(id, x);
        }
    }
    return 0;
}