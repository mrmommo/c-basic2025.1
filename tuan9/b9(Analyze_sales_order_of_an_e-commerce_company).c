#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Order {
    char customer[11];
    char product[11];
    int price;
    char shop[11];
    int time_sec;
} Order;

typedef struct ShopNode {
    char shop[11];
    long long sum;
    struct ShopNode *next;
} ShopNode;

typedef struct CustShopNode {
    char key[22];
    long long sum;
    struct CustShopNode *next;
} CustShopNode;

Order orders[100000];
int num_orders = 0;
long long total_revenue = 0;
ShopNode *shop_hash[1000003];
CustShopNode *custshop_hash[1000003];
int order_indices[100000];
long long prefix[100001];

long long hash_func(char *s) {
    long long h = 0;
    for (int i = 0; s[i]; i++) {
        h = (h * 256LL + s[i]) % 1000003;
    }
    return h;
}

void add_shop(char *shop, int price) {
    long long h = hash_func(shop);
    ShopNode *node = shop_hash[h];
    while (node) {
        if (strcmp(node->shop, shop) == 0) {
            node->sum += price;
            return;
        }
        node = node->next;
    }
    node = (ShopNode *)malloc(sizeof(ShopNode));
    strcpy(node->shop, shop);
    node->sum = price;
    node->next = shop_hash[h];
    shop_hash[h] = node;
}

long long get_shop_sum(char *shop) {
    long long h = hash_func(shop);
    ShopNode *node = shop_hash[h];
    while (node) {
        if (strcmp(node->shop, shop) == 0)
            return node->sum;
        node = node->next;
    }
    return 0;
}

void add_custshop(char *customer, char *shop, int price) {
    char key[22];
    strcpy(key, customer);
    strcat(key, shop);
    long long h = hash_func(key);
    CustShopNode *node = custshop_hash[h];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            node->sum += price;
            return;
        }
        node = node->next;
    }
    node = (CustShopNode *)malloc(sizeof(CustShopNode));
    strcpy(node->key, key);
    node->sum = price;
    node->next = custshop_hash[h];
    custshop_hash[h] = node;
}

long long get_custshop_sum(char *customer, char *shop) {
    char key[22];
    strcpy(key, customer);
    strcat(key, shop);
    long long h = hash_func(key);
    CustShopNode *node = custshop_hash[h];
    while (node) {
        if (strcmp(node->key, key) == 0)
            return node->sum;
        node = node->next;
    }
    return 0;
}

int time_to_seconds(char *time) {
    int h, m, s;
    sscanf(time, "%d:%d:%d", &h, &m, &s);
    return h * 3600 + m * 60 + s;
}

int cmp_time(const void *a, const void *b) {
    int ia = *(int *)a;
    int ib = *(int *)b;
    return orders[ia].time_sec - orders[ib].time_sec;
}

int main() {
    char line[100];
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "#") == 0)
            break;
        char customer[11], product[11], shop[11], time_str[9];
        int price;
        sscanf(line, "%s %s %d %s %s", customer, product, &price, shop,
               time_str);
        int time_sec = time_to_seconds(time_str);
        strcpy(orders[num_orders].customer, customer);
        strcpy(orders[num_orders].product, product);
        orders[num_orders].price = price;
        strcpy(orders[num_orders].shop, shop);
        orders[num_orders].time_sec = time_sec;
        add_shop(shop, price);
        add_custshop(customer, shop, price);
        total_revenue += price;
        num_orders++;
    }
    // prepare time
    for (int i = 0; i < num_orders; i++)
        order_indices[i] = i;
    qsort(order_indices, num_orders, sizeof(int), cmp_time);
    prefix[0] = 0;
    for (int i = 1; i <= num_orders; i++) {
        prefix[i] = prefix[i - 1] + orders[order_indices[i - 1]].price;
    }
    // queries
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "#") == 0)
            break;
        char *query = strtok(line, " ");
        if (strcmp(query, "?total_number_orders") == 0) {
            printf("%d\n", num_orders);
        } else if (strcmp(query, "?total_revenue") == 0) {
            printf("%lld\n", total_revenue);
        } else if (strcmp(query, "?revenue_of_shop") == 0) {
            char *shop = strtok(NULL, " ");
            printf("%lld\n", get_shop_sum(shop));
        } else if (strcmp(query, "?total_consume_of_customer_shop") == 0) {
            char *customer = strtok(NULL, " ");
            char *shop = strtok(NULL, " ");
            printf("%lld\n", get_custshop_sum(customer, shop));
        } else if (strcmp(query, "?total_revenue_in_period") == 0) {
            char *from = strtok(NULL, " ");
            char *to = strtok(NULL, " ");
            int from_sec = time_to_seconds(from);
            int to_sec = time_to_seconds(to);
            int low = 0, high = num_orders;
            while (low < high) {
                int mid = (low + high) / 2;
                if (orders[order_indices[mid]].time_sec >= from_sec)
                    high = mid;
                else
                    low = mid + 1;
            }
            int start = low;
            low = 0, high = num_orders;
            while (low < high) {
                int mid = (low + high) / 2;
                if (orders[order_indices[mid]].time_sec > to_sec)
                    high = mid;
                else
                    low = mid + 1;
            }
            int end = low;
            long long sum = prefix[end] - prefix[start];
            printf("%lld\n", sum);
        }
    }
    return 0;
}
