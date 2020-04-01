/*
    Author: Veeupup
    求链式线性表的倒数第 K 项

    使用双指针法

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
using namespace std;

const int maxn = 1e6;
int now = 0;
int arr[maxn];

int main()
{
    freopen("data.txt", "r", stdin);
    int k, num;
    scanf("%d", &k);
    k *= -1;
    while (scanf("%d", &num) != EOF)
    {
        if (num < 0)
            break;
        arr[now++] = num;
        k++;
    }
    if (k < 0)
        printf("NULL");
    else
        printf("%d", arr[k]);
    return 0;
}