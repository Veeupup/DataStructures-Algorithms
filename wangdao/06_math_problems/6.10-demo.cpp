/* 
    计算 A ^ B 次方
    通过使用快速幂来计算

    例如：3^29
    任何一个数字都可以分解为若干 2^k 的和
    29 = 1 + 2 + 4 + 16
    我们将指数分解为 2^0 + 2^1 + 2^2 + 2^4 也就是 11101
    我们直接计算出 3 的快速幂，也就是 3^1, 3^2, 3^4, 3^8, 3^16 ......
    然后我们通过指数位置是否为 1 来进行快速幂乘法即可计算出幂
    
 */
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

const int MAXN = 10;

/* 二分求幂 */

int main()
{
    // freopen("data.txt","r", stdin);
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        int result = 1;
        while (b != 0)
        {
            if (b % 2 == 1)
                result *= a;
            a *= a;
            b /= 2;
        }
        printf("%d \n", result);
    }

    return 0;
}