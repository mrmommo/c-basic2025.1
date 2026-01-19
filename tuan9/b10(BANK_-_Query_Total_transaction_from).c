#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 25
#define HASH_SIZE 200003 // số nguyên tố lớn

typedef struct Node {
    char account[MAX_LEN];
    long total;
    struct Node *next;
} Node;

Node *hash_table[HASH_SIZE];

/* hash function (djb2) */
unsigned int hash(const char *s) {
    unsigned int h = 5381;
    while (*s)
        h = ((h << 5) + h) + (*s++);
    return h % HASH_SIZE;
}

/* add money to account */
void add_money(const char *acc, int money) {
    unsigned int h = hash(acc);
    Node *cur = hash_table[h];

    while (cur) {
        if (strcmp(cur->account, acc) == 0) {
            cur->total += money;
            return;
        }
        cur = cur->next;
    }

    // chưa tồn tại
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->account, acc);
    node->total = money;
    node->next = hash_table[h];
    hash_table[h] = node;
}

/* get total money */
long get_total(const char *acc) {
    unsigned int h = hash(acc);
    Node *cur = hash_table[h];

    while (cur) {
        if (strcmp(cur->account, acc) == 0)
            return cur->total;
        cur = cur->next;
    }
    return 0;
}

int main() {
    char from[MAX_LEN], to[MAX_LEN], time[10], atm[15];
    int money;

    /* DATA BLOCK */
    while (1) {
        char line[200];
        if (!fgets(line, sizeof(line), stdin))
            break;
        if (line[0] == '#')
            break;

        sscanf(line, "%s %s %d %s %s", from, to, &money, time, atm);

        add_money(from, money);
    }

    /* QUERY BLOCK */
    while (1) {
        char line[100], acc[MAX_LEN];
        if (!fgets(line, sizeof(line), stdin))
            break;
        if (line[0] == '#')
            break;

        sscanf(line, "?total_money_transaction_from %s", acc);
        printf("%ld\n", get_total(acc));
    }

    return 0;
}
/*
Input
T000010010 T000010020 1000 10:20:30 ATM1
T000010010 T000010030 2000 10:02:30 ATM2
T000010010 T000010040 1500 09:23:30 ATM1
T000010020 T000010030 3000 08:20:31 ATM1
T000010030 T000010010 4000 12:40:00 ATM2
T000010040 T000010010 2000 10:30:00 ATM1
T000010020 T000010040 3000 08:20:31 ATM1
T000010040 T000010030 2000 11:30:00 ATM1
T000010040 T000010030 1000 18:30:00 ATM1
#
?total_money_transaction_from T000010010
?total_money_transaction_from T000010030
#
Output
4500
4000
*/