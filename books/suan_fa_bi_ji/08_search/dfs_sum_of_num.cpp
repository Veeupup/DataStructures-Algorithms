/*
    Author: Veeupup
    从 N 个整数中选择 K 个数字，使得这 K 个数字之和恰好等于 X
    如果有多种方案，选择他们中元素平方和最大的一个组合

    这里的难点在于保存我们需要的数据

    input:
    4 2 6   // 4 个数字，选择 2 个，使得和为 6
    2 3 3 4 // 四个数字

    output:
    2 4

    如果我们每个数字可以选择多次：
    input:
        3 5 17
        1 4 7

    output:
        1 1 1 7 7

 */
#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

const int maxn = 100;
int N, K, X, maxSumSqu = -1;
int arr[maxn];
vector<int> temp, ans; // temp 用来保存临时方案， ans 用来保存平方和最大的方案

/* 
    index   代表当前处理到哪里了
    nowK    代表已经选了一个数字了
    sum     代表数字和
    sumSqu  代表数字平方和
 */
void DFS(int index, int nowK, int sum, int sumSqu)
{
    if (nowK == K && sum == X)
    {   // 恰好选了 K 个数字的和为 X
        if(sumSqu > maxSumSqu) {
            maxSumSqu = sumSqu; // 更新最大平方和
            ans = temp;         // 保存最优方案，可以直接进行赋值
        }
        return;
    }
    // 已经处理完 N 个数字，或者当前选择超过 K 个数字，或者和大于 sum
    if(index == N || nowK > K || sum > X) return;
    // 选择 index 数字
    temp.push_back(arr[index]);
    //DFS(index+1, nowK+1, sum+arr[index], sumSqu+arr[index]*arr[index]);
    
    // 如果不限制选择次数，将上方的 index+1 换成 index 即可
    DFS(index, nowK+1, sum+arr[index], sumSqu+arr[index]*arr[index]);

    temp.pop_back();
    // 不选 index 数字
    DFS(index+1, nowK, sum, sumSqu);
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d %d %d", &N, &K, &X);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    DFS(0, 0, 0, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d ", ans[i]);
    }
    
    return 0;
}