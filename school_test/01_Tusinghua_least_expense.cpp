/*
    Author: Veeupup
    题目描述
    在某条线路上有N个火车站，有三种距离的路程，L1，L2，L3,对应的价格为C1,C2,C3.其对应关系如下: 
    距离s    票价 0<S<=L1   C1 L1<S<=L2   C2 L2<S<=L3    C3 输入保证0<L1<L2<L3<10^9,0<C1<C2<C3<10^9
    每两个站之间的距离不超过L3。 当乘客要移动的两个站的距离大于L3的时候，
    可以选择从中间一个站下车，然后买票再上车，所以乘客整个过程中至少会买两张票。 
    现在给你一个 L1，L2，L3，C1，C2,C3。然后是A B的值，其分别为乘客旅程的起始站和终点站。 
    然后输入N，N为该线路上的总的火车站数目，然后输入N-1个整数，分别代表从该线路上的第一个站，到第2个站，第3个站，……，第N个站的距离。 
    根据输入，输出乘客从A到B站的最小花费。

    输入描述:
    以如下格式输入数据：
        L1  L2  L3  C1  C2  C3
        A  B
        N
        a[2]
        a[3]
        ……
        a[N]
    输出描述:
    可能有多组测试数据，对于每一组数据，
    根据输入，输出乘客从A到B站的最小花费

    input:
        1 2 3 1 2 3
        1 2
        2
        2

    output:
        2

 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <climits>
#define N 500
using namespace std;

int L1, L2, L3, C1, C2, C3;
int dist[N], cost[N];   // 记录站点的位置

int Price(int L)
{
    if(L <= L1) return C1;
    else if(L <= L2) return C2;
    else return C3;
}

int main()
{
    freopen("data.txt","r", stdin);
    int from, to, n;
    while (scanf("%d %d %d %d %d %d", &L1, &L2, &L3, &C1, &C2, &C3) != EOF)
    {
        dist[1] = 0;    // 到自己为 0
        scanf("%d %d", &from, &to);
        scanf("%d", &n);
        for (int i = 2; i <= n; i++)
            scanf("%d", &dist[i]);
        cost[from] = 0; // 出发之前车费为 0 
        for (int i = from+1; i <= to; i++)
        {
            cost[i] = INT_MAX;
            for (int j = from; j < i; j++)
            {
                int L = dist[i] - dist[j];  // j 站到 i 站的距离
                if(L <= L3 && cost[j]+Price(L) < cost[i])
                {   // 如果从 j 站买票能比方案更省钱，那就从 j 站买票
                    cost[i] = cost[j] + Price(L);
                }
            }
            
        }
        

    }
    



    return 0;

}