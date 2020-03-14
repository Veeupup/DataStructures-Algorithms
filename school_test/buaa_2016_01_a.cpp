/*
    Author: Veeupup
    给定一个数 n，将这个数字的各位顺序颠倒，称为逆序数 m，例如：
    1234 的逆序数是 4321
    如果 m 是 n 的 k 倍，即 n * k = m，例如：
    输入 1089 输出 1089*9=9081
    如果 m 不是 n 的整数倍，那么输出 n 和 n 的逆序数，例如：
    输入 1234 输出 1234 4321
    在输入 23200 输出 23200 00232

 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[10]; // 记录下每个位置的数字
int pos;    // 记录每个数字的位数
int getReverse(int n)
{
    pos = 0;
    while (n != 0)
    {
        arr[pos++] = n % 10;
        n /= 10;
    }
    int sum = 0;
    for (int i = 0; i < pos; i++)
    {   // 获得逆序的数字
        sum = sum * 10 + arr[i];
    }
    return sum;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int reverse = getReverse(n);
        if (reverse % n == 0)
        { // 如果能够整除
            int k = reverse / n;
            printf("%d*%d=", n, k);
            for (int i = 0; i < pos; i++)
            {
                printf("%d", arr[i]);
            }
        }
        else
        {
            printf("%d ", n);
            for (int i = 0; i < pos; i++)
            {
                printf("%d", arr[i]);
            }
        }
        printf("\n");
    }
    return 0;
}