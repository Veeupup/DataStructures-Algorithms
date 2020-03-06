#include <stdio.h>
#include <stdint.h>

/* 
    动态规划问题：
    最大连续子序列的和
    以 dp[i] 表示以 A[i] 作为结尾的连续序列的最大值
    每个 dp[i] 有两种可能的形式：
        * dp[i] = A[i]  就是 A[i] 最大
        * dp[i] = A[j] + ... + A[i-1] + A[i] = dp[i-1] + A[i]   从A[i]之前的某个地方A[j]开始一直到A[i]

    input:
        5
        1 5 -3 2 4

        6
        1 -2 3 4 -10 6

        4
        -3 -1 -2 -5
    
    output:
        9
        7
        -1


 */

int dp[1000010];    // 动态规划
int a[1000010];     // 记录数组

int main()
{
    freopen("data.txt","r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        dp[0] = a[0];
        int max = a[0];
        for (int i = 1; i < n; i++)
        {   
            if(a[i] > dp[i-1] + a[i]) {
                dp[i] = a[i];
            }else {
                dp[i] = dp[i-1] + a[i];
            }
            if(dp[i] > max) {
                max = dp[i];
            }
        }
        printf("%d\n", max);
    }
    return 0;

}