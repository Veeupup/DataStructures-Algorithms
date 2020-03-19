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
    搬水果，就是经典哈夫曼树
    input:
        3
        9 1 2
        0
    output:
        15
 */

int main()
{
    freopen("data.txt","r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        
        priority_queue<int, vector<int>, greater<int>> myPQ;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            myPQ.push(x);
        }
        int ans = 0;
        while (myPQ.size() > 1)
        {
            int a = myPQ.top();
            myPQ.pop();
            int b = myPQ.top();
            myPQ.pop();
            ans += a + b;
            myPQ.push(a + b);
        }
        printf("%d\n", ans);
    }
    



    return 0;

}