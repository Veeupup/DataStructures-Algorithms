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
    寻找第K小的值
    input:
        6
        2 1 3 5 2 2
        3
    output:
        3
 */

int main()
{
    freopen("data.txt","r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        // 定义最小值堆
        priority_queue<int, vector<int>, greater<int>> myPQ;
        for (int i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            myPQ.push(temp);
        }
        int k;
        scanf("%d", &k);
        int ans;
        int pre = -1;
        while (k--)
        {   
            // 如果当前队列顶部的值等于上一个的值，则一直pop，直到遇到不等的时候
            while (pre == myPQ.top())
            {
                pre = myPQ.top();
                myPQ.pop();
            }
            ans = myPQ.top();   // 保存当前栈顶的值
            pre = ans;          // 下一次循环的和这次的比较
            myPQ.pop();
        }
        printf("%d\n", ans);
    }
    



    return 0;

}