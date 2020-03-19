#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

/* 
    0-1背包问题

    点菜问题

    典型 0-1背包问题
    dp[j] = max(dp[j] , dp[j-w[i]] + v[i] )

    input:
        90 4
        20 25
        30 20
        40 50
        10 18
        40 2
        25 30
        10 8
    output:
        95
        38

 */

#define MAXN 1010
int dp[MAXN]; // dp[i] 代表有 i 元钱时最高的评分
int v[MAXN];  // 记录评分
int w[MAXN];  // 记录权重

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int c, n;
    while (scanf("%d%d", &c, &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &w[i], &v[i]);
        }
        // 初始化所有钱的用途
        for (int i = 0; i <= c; i++)
        {
            dp[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {   // i 代表只包含第 i 个物品时候的最大评分书
            for (int j = c; j >= w[i]; j--)
            {   // 从后往前遍历， 因为在确定 dp[j] 的时候，要保证 dp[j-w[i]] 还没有被修改，从前往后则会有这个问题
                // dp[j] 代表不放入本物品时候最大的价值
                // 而 dp[j-w[i]] + v[i] 代表放入本物品时，剩余空间所能装的物品的最大价值
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
        printf("%d\n", dp[c]);
    }
    return 0;
}
