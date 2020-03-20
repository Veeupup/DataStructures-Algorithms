/*
    Author: Veeupup
    bfs 可以用队列来实现，只有当每一层的所有情况考虑结束之后才能考虑新的

    bfs模板：

    void bfs(int s) {
    queue<int> s;
    q.push(s);
    while(!q.empty()) {
        // 取出队首元素 top
        // 访问队首元素 top
        // 将队首元素出队
        // 将 top 的下一层节点中未曾入队的节点全部入队，并设置成已经入队
    }
}

 */
#include <iostream>
#include <queue>
#include <cstdint>
using namespace std;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        // 取出队首元素 top
        // 访问队首元素 top
        // 将队首元素出队
        // 将 top 的下一层节点中未曾入队的节点全部入队，并设置成已经入队
    }

    int main()
    {
        freopen("data.txt", "r", stdin);

        return 0;
    }