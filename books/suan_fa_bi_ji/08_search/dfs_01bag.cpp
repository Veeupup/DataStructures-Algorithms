/*
    Author: Veeupup
    dfs 解决 01 背包问题

    我们使用一个函数 DFS(int index, int sumW, int sumV) 来推进
    index 代表当前处理到了第 index 件物品
    终止条件是：
    index == n (处理完了最后一件物品，因为下标为 0~n-1) 或者 sumW > maxW （超重）
    每次我们来到一个物品选择的时候，有两种选择，
    * 不带这件物品，则进入状态 DFS(index+1, sumW, sumV)
    * 带这件物品，则进入状态 DFS(index+1, sumW+weight[index], sumV+value[index])

    input:
    5 8         // 5 件物品，背包容量为 8
    3 5 1 2 2   // 重量
    4 5 2 1 3   // 价值

 */
#include <iostream>
#include <cstdint>
using namespace std;

#define N 30
int n, V;    // 记录物品数目和背包能够承受的最大重量
int w[N];  // 记录物品的重量
int c[N];   // 记录物品的价值
int maxValue = 0;   // 最大价值

/* 
    暴力搜索所有情况
 */
void DFS_baoli(int index, int sumW, int sumC) {
    if(index == n) {    // 完成对 n 件物品的选取（死胡同）
        if(sumW <= V && sumC > maxValue)
            maxValue = sumC;    // 不超过背包容量时更新最大价值
        return;
    }
    // 两种可能的状态
    DFS_baoli(index+1, sumW, sumC);   // 不选择第 index 件物品
    DFS_baoli(index+1, sumW + w[index], sumC + c[index]); // 选择第 index 件物品
}

/* 
    DFS 加上减枝
 */
void DFS(int index, int sumW, int sumC) {
    if(index == n) {
        return;
    }
    DFS(index+1, sumW, sumC);   // 不加入第 index 件物品
    if(sumW + w[index] <= V) {
        // 加入后不超重
        if(sumC + c[index] > maxValue) {
            maxValue = sumC + c[index]; // 更新最大价值 maxValue
        }
        DFS(index+1, sumW + w[index], sumC + c[index]);
    }
}

int main()
{
    freopen("data.txt","r", stdin);
    scanf("%d %d", &n, &V);
    for (int i = 0; i < n; i++)
    {   // 每件物品的重量
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < n; i++)
    {   // 每件物品的价值
        scanf("%d", &c[i]);
    }
    DFS(0, 0, 0);
    printf("%d\n", maxValue);
    return 0;

}