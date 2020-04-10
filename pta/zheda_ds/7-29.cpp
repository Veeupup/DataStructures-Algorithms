/* 
    修复牧场

    Huffman 树，让带权路径长度最小
 */
#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq; // 小顶堆

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &n);
    int temp;
    while (n--)
    {
        scanf("%d", &temp);
        pq.push(temp);
    }
    int ans = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    printf("%d", ans);
    return 0;
}