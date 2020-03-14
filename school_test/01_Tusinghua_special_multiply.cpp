/*
    Author: Veeupup
    特殊乘法
    写个算法，对2个小于1000000000的输入，求结果。
    特殊乘法举例：123 * 45 = 1*4 +1*5 +2*4 +2*5 +3*4+3*5

    输入描述:
        两个小于1000000000的数
    输出描述:
        输入可能有多组数据，对于每一组数据，输出Input中的两个数按照题目要求的方法进行运算后得到的结果

    input:
        123 45

    output:
        54

 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    freopen("data.txt", "r", stdin);
    long a, b;
    int numA[10], numB[10];
    int posA, posB;
    while (scanf("%ld %ld", &a, &b) != EOF)
    {
        posA = 0, posB = 0;
        while (a != 0)
        {
            numA[posA++] = a % 10;
            a /= 10;
        }
        while (b != 0)
        {
            numB[posB++] = b % 10;
            b /= 10;
        }
        int sum = 0;
        for (int i = 0; i < posA; i++)
        {
            for (int j = 0; j < posB; j++)
            {
                sum += numA[i] * numB[j];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}