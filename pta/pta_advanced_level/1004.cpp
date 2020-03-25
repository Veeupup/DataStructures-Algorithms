/*
    Author: Veeupup
    输出每一层的叶子结点

    我们可以使用队列来做，在进行层序遍历的时候
    我们就可以知道每个节点所在的层数
    而根据该结点子结点的数目可以判断出是否是叶结点

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 105;

struct Node {
    int level;
    vector<int> child;  // 保存孩子结点个数
}nodes[maxn];

int max(int a, int b) {
    return a > b ? a : b;
}

int main()
{
    freopen("data.txt","r", stdin);
    int n, m;
    scanf("%d", &n);
    if(n == 0)  return 0;
    scanf("%d", &m);
    int parentId, k, childId;        
    for (int i = 0; i < m; i++)
    {   // 读取
        scanf("%d %d", &parentId, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &childId);
            nodes[parentId].child.push_back(childId);
        }
    }
    queue<int> q;
    nodes[1].level = 1;
    q.push(1);
    int level[maxn] = {0};  // 保存每层叶结点的数目
    int maxLevel = 1;   // 记录最大层数
    while (!q.empty())
    {
        int topId = q.front();
        q.pop();
        int nowLevel = nodes[topId].level;
        for (int i = 0; i < nodes[topId].child.size(); i++)
        {
            int childId = nodes[topId].child[i];    // 孩子 id
            nodes[childId].level = nowLevel + 1;
            maxLevel = max(maxLevel, nowLevel + 1); // 记录最大层数
            q.push(childId);
        }
        if(nodes[topId].child.size() == 0) {
            level[nowLevel]++;  // 如果当前是叶子结点，那么自增
        }
    }
    if(n == 1)
        printf("1\n");
    else {
        for (int i = 1; i <= maxLevel; i++)
        {
            if(i == 1)
                printf("%d", level[i]);
            else 
                printf(" %d", level[i]);
        }
        
    }


    return 0;

}