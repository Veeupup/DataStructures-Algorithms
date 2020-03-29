/*
    Author: Veeupup
    最大子列和问题

    动态规划，用 dp[i] 代表以 A[i] 结尾的最大子序列的和
    状态转移方程：
    dp[i] = max( A[i], dp[i-1]+A[i])

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <algorithm>
using namespace std;

const int maxn = 1e5+5;
int A[maxn];
int dp[maxn];

int main()
{
    freopen("data.txt","r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {   // 读取 A[i]
        scanf("%d", &A[i]);
    }
    dp[0] = A[0];
    int maxAns = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(A[i], dp[i-1] + A[i]);
        if(dp[i] > maxAns) {
            maxAns = dp[i];
        }
    }
    printf("%d", maxAns);
    return 0;
}