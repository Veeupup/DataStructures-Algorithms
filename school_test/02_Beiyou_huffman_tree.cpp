/*
    Author: Veeupup
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {   
        priority_queue<int, vector<int>, greater<int>> pq;  // 小顶堆
        int val;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &val);
            pq.push(val);
        }
        int ans = 0;
        while (pq.size() > 1)
        {   // 当只有一个元素的时候就可以结束了
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ans += a + b;
            pq.push(a + b);
        }
        printf("%d\n", ans);
        
    }
    return 0;

}