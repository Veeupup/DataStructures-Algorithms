/*
    Author: Veeupup
    输入N个（N<=10000）数字，求出这N个数字中的最大值和最小值。每个数字的绝对值不大于1000000。
    输入描述:
        输入包括多组测试用例，每组测试用例由一个整数N开头，接下去一行给出N个整数。
    输出描述:
        输出包括两个整数，为给定N个数中的最大值与最小值。

    input:
        5
        1 2 3 4 5
        3
        3 7 8
    
    output:
        5 1
        8 3

 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <climits>
using namespace std;

int main()
{
    freopen("data.txt","r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int max = INT_MIN;
        int min = INT_MAX;
        int temp;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            if(temp > max)
                max = temp;
            if(temp < min)
                min = temp;
        }
        printf("%d %d\n", max, min);
    }
    return 0;
}