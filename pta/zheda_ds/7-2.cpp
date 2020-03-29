/*
    Author: Veeupup
    一元多项式的乘法和加法运算

    设计函数分别求两个一元多项式的乘积与和。

    输入：
        输入分2行，每行分别先给出多项式非零项的个数，
        再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）
        数字间以空格分隔。

    输出格式可以使用 flag 来使用，而不是通过计数来实现

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
using namespace std;
typedef long long ll;

const int maxn = 2010; // 1000 * 1000 = 1e6

// 数字1 数字2 乘积结果 和结果， 设置为 ll 避免溢出
// 系数都初始化为 0
ll num1[maxn] = {0}, num2[maxn] = {0}, ans1[maxn] = {0}, ans2[maxn] = {0};

// 乘法法则
// 指数相加，系数相乘
void multiply()
{
    int count1 = 0;
    for (int i = 1000; i >= 0; i--)
    { // 如果 num1 的指数为 i 时系数为 0 则跳过
        if (num1[i] == 0)
            continue;
        for (int j = 1000; j >= 0; j--)
        {
            if (num2[j] == 0)
                continue;                     // 如果 num2 的指数为 i 时系数为 0 则跳过
            ans1[i + j] += num1[i] * num2[j]; // 系数相乘，指数相加
        }
    }
    int flag = 0;
    for (int i = maxn; i >= 0; i--)
    {
        if (ans1[i] == 0)
            continue;
        if(flag) {
            printf(" %d %d", ans1[i], i);
            flag++;
        }else {
            printf("%d %d", ans1[i], i);
            flag++;
        }
    }
    if (flag == 0)
    { // 如果全部为 0
        printf("0 0");
    }
    printf("\n");
}

// 加法法则
// 指数相同的系统相加减
void add()
{
    int count = 0;
    for (int i = 1000; i >= 0; i--)
    {
        if (num1[i] == 0 && num2[i] == 0)
            continue;                // 只有当二者都为 0 的时候才跳过
        ans2[i] = num1[i] + num2[i]; // 系数相加
        if (ans2[i] != 0)
            count++;
    }
    int flag = 0;
    for (int i = 1000; i >= 0; i--)
    {
        if (ans2[i] == 0)
            continue;
        if(flag) {
            printf(" %d %d", ans2[i], i);
            flag++;
        }else {
            printf("%d %d", ans2[i], i);
            flag++;
        }
    }
    if(flag == 0) {
        printf("0 0");
    }
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int factor, expo;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &factor, &expo);
        num1[expo] += factor; // 指数为 expo 的系数为 factor
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &factor, &expo);
        num2[expo] += factor; // 指数为 expo 的系数为 factor
    }
    multiply();
    add();
    return 0;
}