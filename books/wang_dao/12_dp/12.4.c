#include<stdio.h>
#include<stdint.h>

/* 
    动态规划
        最长递增子序列
    拦截导弹（最大不增子序列）

    假设序列为 height[N]
    那么设 dp[i] 为以 i 处为结尾的最大递减子序列的长度
    那么每个位置的 dp[i] 有两种取法
        * 当 height[i] > height[j] 就是大于之前的值的时候,这个时候 dp[i] = 1,因为只有他本身
        * 当 height[i] <= height[j] 时, dp[i] = dp[j] + 1
          而我们只需要从前往后遍历,遍历到 i 之前的位置,找到满足条件的最大的 dp[j] + 1 (if height[i] <= height[j])

    input:
        8
        300 207 155 300 299 170 158 65  
    output:
        6

 */

#define N 25
int height[N];
int dp[N];      // 用来记录以 height[i] 为结尾的时候最长递增子序列的长度  

int max(int a, int b) {
    return a > b ? a : b;
}

int main()
{
    freopen("data.txt","r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &height[i]);
        }
        int maxVal = 1;
        for (int i = 0; i < n; i++)
        {   // 从前往后计算每个位置最大的 dp[i]
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {   // 从开始遍历到 i 处，看每个位置的值是否不大于height[j],是的话,就取其中大的那个值
                if (height[i] <= height[j])
                {   
                    dp[i] = max(dp[i], dp[j] + 1);
                    if(dp[i] > maxVal) {
                        maxVal = dp[i];
                    }
                }
            }
        }
        printf("%d\n", maxVal);
    }
    
    



    return 0;
}