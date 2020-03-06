#include <stdio.h>
#include <stdint.h>
#include <math.h>

/* 质数判定 */

int Judge(int n)
{
    if(n < 0 || n == 0 || n == 1)
        return 1;
    int flag = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if(Judge(n) == 0) {
            printf("yes\n");
        }else {
            printf("no\n");
        }
    }
    int bound = sqrt(10);
    printf("%d\n", bound);
    return 0;
}