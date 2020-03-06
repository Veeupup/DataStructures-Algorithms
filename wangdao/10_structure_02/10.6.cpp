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
    Huffman Tree 哈夫曼树🌲
        带权路径长度和最小的树

    input:
        5  
        1 2 2 5 9
    output:
        37
 */

int main()
{
    freopen("data.txt","r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        // 重新定义优先队列，第三个参数来形成最小值堆
        priority_queue<int, vector<int>, greater<int>> myPQ;
        while (n--)
        {
            int x;
            scanf("%d", &x);
            myPQ.push(x);
        }
        int answer = 0;
        while (myPQ.size() > 1)
        {
            int a = myPQ.top();
            myPQ.pop();
            int b = myPQ.top();
            myPQ.pop();
            answer += a + b;
            myPQ.push(a+b);
        }
        printf("%d\n", answer);
    }
    return 0;

}