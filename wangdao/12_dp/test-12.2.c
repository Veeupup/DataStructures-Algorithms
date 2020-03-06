#include<stdio.h>
#include<stdint.h>

/* 
    最大连续子序列

    首先是正常的最大连续子序列的一个动态规划问题
    dp[i] = max(arr[i], dp[i-1] + arr[i])
    我们只需要保存最大的那个值的结束的位置
    然后我们从结束的位置从后往前遍历，找到第一个 dp[i] 大于 0 的位置即可
    （此处的操作是从后往前找到第一个 dp[i] 小于 0 的数字，如果全部都大于 0，我们就取到了第一个数字的位置

    输入描述:
    测试输入包含若干测试用例，每个测试用例占2行，第1行给出正整数K( K< 10000 )，
    第2行给出K个整数，中间用空格分隔。当K为0时，输入结束，该用例不被处理。
    
    输出描述:
        对每个测试用例，在1行里输出最大和、最大连续子序列的第一个和最后一个元素，中间用空格分隔。
        如果最大连续子序列不唯一，则输出序号i和j最小的那个（如输入样例的第2、3组）。
        若所有K个元素都是负数，则定义其最大和为0，输出整个序列的首尾元素。

    input:
        6
        -2 11 -4 13 -5 -2
        10
        -10 1 2 3 4 -5 -23 3 7 -21
        6
        5 -8 3 2 5 0
        1
        10
        3
        -1 -5 -2
        3
        -1 0 -2
        0
    output:
        20 11 13
        10 1 4
        10 3 5
        10 10 10
        0 -1 -2
        0 0 0


 */
#define MAXN 10000

int arr[MAXN];
int dp[MAXN];

int max(int a, int b) {
    return a > b ? a : b;
}

void MaxSequence(int k) {
    int maxVal = -1 * MAXN;     // 记录最大值
    int start = 0, end = 0; // 记录开始和结束位置的下标，初始为最大值，只要有比这个小的就保存
    for (int i = 0; i < k; i++)
    {
        if(i == 0) {
            start = 0;
            dp[i] = arr[i];
        }else {
            dp[i] = max(arr[i], arr[i] + dp[i-1]);
        }
        if(dp[i] > maxVal) {
            // 如果当前值大于最大值，那我们记录下末尾的值
            end = i;
        }
        maxVal = max(dp[i], maxVal);
    }
    int flag = 0;   // 看能否找到小于 0 的数字
    for (int i = end; i >= 0; i--)
    {   // 从后往前遍历，找到第一个小于0的dp[i]，如果没有的话，那么就找到了第一个
        if(dp[i] < 0) {
            start = i;
            flag = 1;
            break;
        }
    }
    if(flag == 1) { // 找到了小于 0 的数字，那么往后看一个
        start += 1;
    }
    printf("%d %d %d\n", maxVal, arr[start], arr[end]);
}

int LessThanZero(int k) {
    for (int i = 0; i < k; i++)
    {
        if(arr[i] >= 0) {
            // 只要有一个大于等于0的，那么就不是这种情况了
            return 1;
        }
    }
    // 全部都小于0
    return 0;
}

int main()
{
    freopen("data.txt","r", stdin);
    int k;
    while (scanf("%d", &k) != EOF)
    {
        if(k == 0)
            break;
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &arr[i]);
        }
        if(LessThanZero(k) == 0) {
            // 如果全部小于 0，那么输出 0 和首尾数字
            printf("0 %d %d\n", arr[0], arr[k-1]);
        }else {
            MaxSequence(k);
        }
    }
    
    return 0;
}