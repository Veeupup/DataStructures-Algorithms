#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* 
    二叉树
 */

int count;

int CountNodes(int m, int n) {
    if(m > n) {
        return 0;
    }else {
        return 1 + CountNodes(2 * m, n) + CountNodes(2 * m + 1, n);
    }
}

int getAll(int m, int n)
{
    if (2 * m <= n)
    {
        count++;
        getAll(2 * m, n);
    }
    if (2 * m + 1 <= n)
    {
        count++;
        getAll(2 * m + 1, n);
    }
}

int main()
{
    freopen("data.txt", "r", stdin);
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        if(m == 0 && n == 0)
            break;
        count = 1;
        // getAll(m, n);
        // printf("%d\n", count);
        printf("%d\n", CountNodes(m, n));
    }

    return 0;
}