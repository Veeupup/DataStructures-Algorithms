#include <stdio.h>
#include <stdint.h>
#include <string.h>

// 递归
int Fibonacci(int x)
{
    if (x == 0 || x == 1)
    {
        return x;
    }
    else
    {
        return Fibonacci(x - 1) + Fibonacci(x - 2);
    }
}

int dp[1000];
// 动态规划
int dp_fibon(int n)
{
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    // freopen("data.txt", "r", stdin);
    int n;
    dp[0] = 0;
    dp[1] = 1;
    while (scanf("%d", &n) != EOF)
    {
        // printf("%d\n", Fibonacci(n));
        printf("%d\n", dp_fibon(n));
    }

    return 0;
}