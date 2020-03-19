#include <stdio.h>
#include <stdint.h>

/* 
    最长上升子序列和

    在所有的上升子序列中,找到最大的子序列的和
    我们只需要记录,以 i 位置结束的位置, 所形成的最长子序列的和

    input:
        7
        1 7 3 5 9 4 8
    iuput:
        18


 */

#define N 1010
int arr[N];
int dp[N]; //  最长递增子序列

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int maxVal = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i] = arr[i];
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j])
                { // 满足递增的子序列, 记录下 dp[i] 是子序列的和
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                    if (dp[i] > maxVal)
                    {
                        maxVal = dp[i];
                    }
                }
            }
        }
        printf("%d\n", maxVal);
    }

    return 0;
}