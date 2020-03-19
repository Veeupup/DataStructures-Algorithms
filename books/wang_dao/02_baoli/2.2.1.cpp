/* 逆序数字 */
#include <iostream>
#include <cstdio>
using namespace std;

/* 从原数字的低位开始计算，每次通过求余取最第一位，然后加上该位数字，再乘法计算 */
int reverse(int n)
{
    int result = 0;
    while (n != 0)
    {
        result *= 10;
        result += n % 10;
        n /= 10;
    }
    return result;
}

int main()
{
    for (int i = 1000; i < 1200; i++)
    {
        if (i * 9 == reverse(i))
        {
            cout << i << endl;
        }
    }

    return 0;
}