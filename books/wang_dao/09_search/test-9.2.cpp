#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

/* 
    神奇的口袋

    采用递归思想：
    1.物品n个，放入 items 数组中
    2.递归函数 count(i, sum) = count(i+1, sum-items[i]) + count(i+1, sum);
        count(i+1, sum-items[i]) 代表从第 i+1 个物品开始，剩下的里面寻找体积和为 sum-a[i]
            包含了 a[i]
        count(i+1, sum) 代表从 i+1 个物品开始，剩下里面找合为 sum 的
            不包含 a[i]
    input:
        3
        20
        20
        20

    output:
        3

 */

int n = 1;
int items[100] = {0};

int count(int i, int sum)
{
    if (sum == 0)
        return 1;
    if (i == n || sum < 0)
        return 0;
    return count(i + 1, sum - items[i]) + count(i + 1, sum);
}

int main()
{
    freopen("data.txt", "r", stdin);
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &items[i]);
        }
        printf("%d\n", count(0, 40));
    }
    return 0;
}