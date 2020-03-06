/* 多行输入可以使用 scanf() != EOF */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x, y, z;
    while ((scanf("%d%d%d%d", &n, &x, &y, &z)) != EOF)
    {
        int i = 0, j = 0, num = 0, value = 0, ci = 0, cj = 0;
        num += (1000 * x + 100 * y + 10 * z);
        for (i = 1; i < 10; ++i)
            for (j = 0; j < 10; ++j)
            {
                value = (num + 10000 * i + j);
                if (value % n == 0)
                {
                    ci = i;
                    cj = j;
                }
            }
        if (ci == 0 && cj == 0)
            printf("0\n");
        else
            printf("%d %d %d\n", ci, cj, (num + 10000 * ci + cj) / n);
    }
    return 0;
}