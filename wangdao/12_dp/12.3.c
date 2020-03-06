#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>

/* 
    动态规划：
    最大子矩阵

    从第 i 行到第 j 行，求最大的子矩阵的和
    如果 
        i == j, 那么其实也就是求第 i 行的最大子序列的和
        i != j, 那么我们需要计算从第 i 行到第 j 行所有行累加起来，
                得到一个只有一维的数组,然后求这个数组的最大子序列的和即可

    为了方便求从第 i 行到第 j 行的和
    我们可以准备一个辅助矩阵 total 用来存储从第一行到第i行的和,
    如果需要第 i 行到第 j 行的和的话,使用减法就可以进行计算


    input:
        4
        0 -2 -7 0
        9 2 -6 2
        -4 1 -4  1
        -1 8  0 -2
    output:
        15

 */

#define MAXN 100

int matrix[MAXN][MAXN]; // 记录矩阵
int total[MAXN][MAXN];  // 辅助矩阵,记录从第 1 行一直加到第 i 行的和
int arr[MAXN];          // 我们所需要计算的一维数组
int dp[MAXN];           // dp 矩阵

// 最大值函数
int max(int a, int b) {
    return a > b ? a : b;
}

// 最大子序列的和
int MaxSequence(int n) {
    int maxVal = 0;
    for (int i = 0; i < n; i++)
    {
        if(i == 0) {
            dp[i] = arr[i];
        }else {
            dp[i] = max(arr[i], dp[i-1] + arr[i]);
        }
        maxVal = max(dp[i], maxVal);
    }
    return maxVal;
}

// 最大子矩阵的求解
int MaxSubMatrix(int n) {
    int maxVal = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {   
            for (int k = 0; k < n; k++)
            {
                if(i == 0) {
                    arr[k] = total[j][k];
                }else {
                    arr[k] = total[j][k] - total[i-1][k];   //从第 i 行到第 j 行的和，计算成一维数组
                }
            }
            int curr = MaxSequence(n);  // 计算从第 i 行到第 j 行的最大子序列的和
            maxVal = max(maxVal, curr);
        }
    }
    return maxVal;
}


int main()
{
    freopen("data.txt","r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        // 读取输入
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &matrix[i][j]);
            }
        }
        // 构造辅助矩阵
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i == 0) {    // 如果是第一行的和就是矩阵本身
                    total[i][j] = matrix[i][j];
                }else {         // 第 i 行的和等于本行的数字加上上一行的和
                    total[i][j] = total[i-1][j] + matrix[i][j];
                }
            }
        }
        int maxVal = MaxSubMatrix(n); 
        printf("%d\n", maxVal);
    }
    return 0;
}