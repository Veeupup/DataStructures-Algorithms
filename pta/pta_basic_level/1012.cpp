/*
    Author: Veeupup
 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    int a, a1 = 0, a2 = 0, a3 = 0, a5 = 0;
    float a4 = 0.0;
    int sum[1001];
    int c;
    int i, j = 0, k = 0;
    scanf("%d", &N);
    getchar();
    for (i = 0; i < N; i++)
    {
        scanf("%d", &a);
        switch (a % 5)
        {
        case 0:
            if (a % 2 == 0) //偶数
                a1 += a;
            break;
        case 1:
            if (j % 2 == 1)
                a2 -= a; // n2+n4+n6+....
            if (j % 2 == 0)
                a2 += a; // n1+n3+n5+....
            j++;
            break;
        case 2:
            a3++; //个数++即可
            break;
        case 3:
            a4 += a; //求出整数，然后在输出的时候除以个数
            k++;     //统计个数
            break;
        case 4:
            if (a > a5)
                a5 = a; //找出最大值
            break;
        }
    }
    for (i = 0; i < 5; i++)
    {
        if (i != 0)
            printf(" ");
        if (i == 0 && a1 == 0 || i == 1 && j == 0 || i == 2 && a3 == 0 || i == 3 && a4 == 0 || i == 4 && a5 == 0)
        {
            printf("N");
            continue;
        }
        if (i == 0)
            printf("%d", a1);
        if (i == 1)
            printf("%d", a2);
        if (i == 2)
            printf("%d", a3);
        if (i == 3)
            printf("%.1f", a4 / k); //和再除个数，精确度为0.1
        if (i == 4)
            printf("%d", a5);
    }
    return 0;
}
