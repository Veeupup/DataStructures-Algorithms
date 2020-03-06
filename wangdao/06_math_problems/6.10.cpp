#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

/* 计算 A ^ B 最后三位，快速幂求法 */

int FastExp(int a, int b, int mod)
{
    int ans = 1;
    while (b != 0)
    { // 一边计算每个位置 2 的余数，然后来乘法运算
        if (b % 2 == 1)
        {
            ans *= a;
            ans %= mod;
        }
        b /= 2;
        a *= a;
        a %= mod;
    }
    return ans;
}

int main()
{
    // freopen("data.txt","r", stdin);
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        if (a == 0 && b == 0)
            break;
        printf("%d\n", FastExp(a, b, 1000));
    }
    return 0;
}