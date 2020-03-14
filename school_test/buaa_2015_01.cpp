/*
    Author: Veeupup
    求“相亲数”，输入两个正整数 a，b
    若 a 的所有约数（包括 1 不包括 a 本身）的和等于 b，
    且 b 所有约数和等于 a，则称 a， b 为相亲数。
    要求分别输出两个正整数约数求和的式子，然后换行输出 1 或者 0 代表是否为相亲数

    input:
        220 284

    output:
        220,1+2+4+5+10+11+20+22+44+55+110=284
        284,1+2+4+71+142=220
        1

 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100], pos;
int getNum(int a)
{
    printf("%d,", a);
    pos = 0;
    for (int i = 1; i < a; i++)
    {
        if (a % i == 0) // 如果能整除，则保存这个数
            arr[pos++] = i;
    }
    int sumA = 0;
    for (int i = 0; i < pos; i++)
    {
        sumA += arr[i];
        printf("%d", arr[i]);
        if (i != pos - 1)
        {
            printf("+");
        }
    }
    printf("=%d\n", sumA);
    return sumA;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        int x = getNum(a);
        int y = getNum(b);
        if(x == b && y == a) 
            printf("1\n");
        else
            printf("0\n");
        
    }

    return 0;
}