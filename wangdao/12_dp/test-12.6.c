#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

/* 
    集邮问题


    状态
        集合中数字
        dp[i][j]    0   1   2   3   4   5   6   7   8   9   10
        1           0   1   ∞   ∞   ∞   ∞   ∞   ∞   ∞   ∞   ∞
        1 3         0   1   ∞   1   2   ∞   ∞   ∞   ∞   ∞   ∞
        1 3 3       0   1   ∞   1   2   ∞   2   3   ∞   ∞   ∞
        1 3 3 3     0   1   ∞   1   2   ∞   2   ∞   ∞   3   4
        1 3 3 3 4   0   1   ∞   1   2   2   2   2   3   3   3  

    前者为不加入这张邮票进去，后者为放入这张邮票
    dp[j] = min( dp[j], dp[j-stamp[i]] + 1 )

 */

#define INF 1000
int stamp[1000]; // 记录邮票价值
int dp[1000];

int Min_Stamp(int num, int deno)
{
    int i, j;
    // 初始化
    for (i = 0; i <= deno; i++)
    {
        dp[i] = (i == 0) ? 0 : INF;
    }
    for (i = 0; i < num; i++)
    {
        // 从后往前，记录每每一个数值的邮票可以组成的最小邮票数
        for (j = deno; j >= stamp[i]; j--)
        {
            if (dp[j - stamp[i]] != INF)
            {
                dp[j] = (dp[j] < dp[j - stamp[i]] + 1) ? dp[j] : dp[j - stamp[i]] + 1;
            }
        }
    }
    return dp[deno] == INF ? 0 : dp[deno];
}

int main()
{
    freopen("data.txt", "r", stdin);
    int num, deno;
    while (scanf("%d %d", &deno, &num) != EOF)
    {
        for (int i = 0; i < num; i++)
            scanf("%d", stamp + i);
        printf("%d", Min_Stamp(num, deno));
    }

    return 0;
}