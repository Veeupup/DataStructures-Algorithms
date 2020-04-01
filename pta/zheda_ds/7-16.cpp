/*
    Author: Veeupup
    一元多项式求导

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
using namespace std;

const int maxn = 1e5;

int arr[maxn];

int main()
{
    freopen("data.txt", "r", stdin);
    int factor, index;
    bool flag = false;
    while (scanf("%d%d", &factor, &index) != EOF)
    {
        if (index == 0)
            continue;
        factor *= index--;
        if (factor != 0)
        {   // 不为 0 的系数输出
            if (flag)
            {
                printf(" %d %d", factor, index);
            }
            else
            {
                printf("%d %d", factor, index);
                flag = true;
            }
        }
    }
    if(!flag) {
        printf("0 0");
    }
    return 0;
}