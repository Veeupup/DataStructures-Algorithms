/*
    Author: Veeupup
    有一棵树，输出某一深度的所有节点，有则输出这些节点，无则输出EMPTY。该树是完全二叉树。

    输入有多组数据。
    每组输入一个n(1<=n<=1000)，然后将树中的这n个节点依次输入，再输入一个d代表深度。

    input:
    4
    1 2 3 4
    2

    output:
    2 3

 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cmath>
#define N 1010
#define DEBUG
using namespace std;

int pow(int n)
{
    int rev = 1;
    for (int i = 1; i <= n; i++)
    {
        rev *= 2;
    }
    return rev;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int arr[N]; // 保存二叉树数据
    int n, depth, end;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &depth);
        int start = pow(depth - 1) - 1;
        int len = pow(depth - 1);
        end = min(start + len - 1, n - 1);
        if (start >= n)
        {
            printf("EMPTY\n");
        }
        else
        {
            for (int i = start; i <= end; i++)
            {
                if (i == start)
                {
                    printf("%d", arr[i]);
                }
                else
                {
                    printf(" %d", arr[i]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}