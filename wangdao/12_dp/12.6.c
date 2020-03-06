#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>

/* 
    最长公共子序列的长度

    使用一个 dp[i][j] 数组表示
        以字符串1的 下标i 处为结尾，字符串2的 下标j末尾结尾的最长子序列的长度

    当两个位置的字符 s1[i] 和 s2[j] 位置字符比较时，有两种情况：
    * s1[i] == s2[j], 此时 dp[i][j] = dp[i-1][j-1] + 1
    * s1[i] == s2[j], 此时 dp[i][j] = max( dp[i-1][j], dp[i][j-1] ) 
    * 

    注意一个细节：
        我们输入字符串时，从位置 1 开始输入

    input:
        abcgbc abfcab
        programming contest
        abcd mnp

    output:
        4
        2
        0

 */

#define N 25
int dp[N][N];

int max(int a, int b) {
    return a > b ? a : b;
}

int main()
{
    freopen("data.txt","r", stdin);
    char s1[20];
    char s2[20];
    // 初始化边界
    for (int i = 0; i < N; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }   
    while (scanf("%s %s", s1 + 1, s2 + 1) != EOF)   // 从下标 1 开始输入！，细节
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