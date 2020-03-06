#include <iostream>
#include <cstdio>
using namespace std;

bool aboutSeven(int n)
{
    // 能被 7 整除
    if (n % 7 == 0)
        return true;
    // 遍历每个位置上的数字
    while (n != 0)
    {
        if (n % 10 == 7)
            return true;
        n /= 10;
    }
    // 都不满足则无关
    return false;
}

int main()
{
    int n, sum;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (!aboutSeven(i))
        {
            sum += i * i;
        }
    }
    printf("%d", sum);
    return 0;
}