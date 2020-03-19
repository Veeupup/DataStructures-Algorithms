#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>

/* 
    最长公共子序列的长度


 */
#define N 110
char s1[N];
char s2[N];
int dp[N][N];

int max(int a, int b) {
    return a > b ? a : b;
}

int main()
{
    // freopen("data.txt","r", stdin);
    // 初始化边界
    for (int i = 0; i < N; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    while (scanf("%s %s", s1+1, s2+1) != EOF)
    {
        int i, j;
        int len1 = strlen(s1+1);
        int len2 = strlen(s2+1);
        for (i = 1; i <= len1; i++)
        {
            for (j = 1; j <= len2; j++)
            {
                if(s1[i] == s2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        printf("%d\n", dp[len1][len2]);
    }
    return 0;
}