#include <stdio.h>z
#include <stdint.h>

/* 
    合唱队形

    N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学不交换位置就能排成合唱队形。 
    合唱队形是指这样的一种队形：
        设K位同学从左到右依次编号为1, 2, …, K，他们的身高分别为T1, T2, …, TK， 
        则他们的身高满足T1 < T2 < … < Ti , Ti > Ti+1 > … > TK (1 <= i <= K)。 
        你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。

    input:
        8
        186 186 150 200 160 130 197 220

    output:
        4
 */

#define N 110
int height[N];
int dp1[N]; // 记录最长升序
int dp2[N]; // 记录最长降序

int max(int a, int b)
{
    return a > b ? a : b;
}

int func(int n)
{
    int i, j;

    // 从前往后求最长升序
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (height[i] > height[j])
            { // 前面的比他小
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    // 从后往前求最长升序, 我们这个时候不是求从前往后的降序！！
    // 而是求从后往前的升序！！！！
    // 二者并不等价！！！
    for (i = n-1; i >= 0; i--)
    {
        for (j = i+1; j < n; j++)
        {
            if (height[i] > height[j])
            {
                // height[i] 比其之前的 height[j] 小
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }
    //
    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j < i; j++)
    //     {
    //         if(height[i] < height[j]) {
    //             dp2[i] = max(dp2[i], dp2[j] + 1);
    //         }
    //     }
    // }
    
    int min = n;
    for (int i = 0; i < n; i++)
    {
        int temp = n - dp1[i] - dp2[i] + 1;
        if (temp < min)
            min = temp;
    }
    return min;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {        
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &height[i]);
            dp1[i] = 1;
            dp2[i] = 1;
        }
        int minVal = func(n);
        printf("%d\n", minVal);
    }
    return 0;
}