#include <stdio.h>
#include <stdint.h>

/* 
    n!
    input:
        1
        2
        3
        4
        5
        6
    output:
        1
        2
        6
        24
        120
        720
 */

long long Factorial(int n)
{
    // 递归写法
    if (n == 0)
        return 1;
    else
        return n * Factorial(n - 1);

    // 非递归
    // if(n == 0)
    //     return 1;
    // int result = 1;
    // while (n != 1)
    // {
    //     result *= n--;
    // }
    // return result;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%lld\n", Factorial(n));
    }

    return 0;
}