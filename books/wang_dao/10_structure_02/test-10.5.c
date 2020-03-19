#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct record
{
    char id[20];
    char reg[20];
    char leave[20];
} record;

int cmp0(record *a, record *b)
{
    return strcmp(a->reg, b->reg);
}

int cmp1(record *a, record *b)
{
    return strcmp(b->leave, a->leave);
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n, i;
    while (scanf("%d", &n) != EOF)
    {
        record r[n];
        for (int i = 0; i < n; i++)
            scanf("%s%s%s", r[i].id, r[i].reg, r[i].leave);
        qsort(r, n, sizeof(record), cmp0);
        printf("%s ", r[0].id);
        qsort(r, n, sizeof(record), cmp1);
        printf("%s\n", r[0].id);
    }
    return 0;
}