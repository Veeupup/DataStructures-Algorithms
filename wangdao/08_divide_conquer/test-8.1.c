#include <stdio.h>
#include <stdint.h>

/* 
    杨辉三角
        初始化我们的杨辉三角每个位置上的数字
    input:
        6
    output:
        1 1 
        1 2 1 
        1 3 3 1 
        1 4 6 4 1 
        1 5 10 10 5 1 
 */

#define MAXN 20

int arr[MAXN][MAXN];

void Initial()
{
    arr[0][0] = 1;
    arr[0][1] = 1;
    for (int i = 1; i < MAXN - 1; i++)
    {
        for (int j = 0; j <= i + 1; j++)
        {
            if (j == 0 || j == i + 1)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }
}

// 递归写法
int YangHui(int i, int j)
{
    if (j == 1 || j == i)   // 第一个数字或者最后一个数字是 1
        return 1;
    else                    // 其他的数字为上一行的这一列和上一行的前一列之和
        return YangHui(i - 1, j) + YangHui(i - 1, j - 1);
}

int main()
{
    // Initial();
    int n;
    while (scanf("%d", &n) != EOF)
    {
        // 递归写法
        for (int i = 2; i <= n; i++)    // 每一行有几个数字
        {
            for (int j = 1; j <= i; j++)    // 计算每一行的数字
            {          
                printf("%d ", YangHui(i, j));
            }
            printf("\n");
        }

        // 自己初始化写法
        // for (int i = 0; i < n - 1; i++)
        // {
        //     for (int j = 0; j <= i + 1; j++)
        //     {
        //         printf("%d ", arr[i][j]);
        //     }
        //     printf("\n");
        // }
    }
    return 0;
}