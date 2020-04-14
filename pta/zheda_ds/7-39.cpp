#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> posiGoods, posiDiscounts;   // 正数采用大顶堆
priority_queue<int, vector<int>, greater<int>> negaGoods, negaDiscounts;    // 负数采用小顶堆

int main()
{
    freopen("data.txt", "r", stdin);
    int n, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if (temp > 0)
            posiGoods.push(temp);
        else
            negaGoods.push(temp);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if (temp > 0)
            posiDiscounts.push(temp);
        else
            negaDiscounts.push(temp);
    }
    int sum = 0;
    while (!posiGoods.empty() && !posiDiscounts.empty())
    {
        sum += posiGoods.top() * posiDiscounts.top();
        posiDiscounts.pop();
        posiGoods.pop();
    }
    while (!negaGoods.empty() && !negaDiscounts.empty())
    {
        sum += negaGoods.top() * negaDiscounts.top();
        negaGoods.pop();
        negaDiscounts.pop();
    }
    printf("%d", sum);
    return 0;
}