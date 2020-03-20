/*
    Author: Veeupup
 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <vector>
#include <cctype>
#include <queue>
#include <algorithm>
using namespace std;

#define maxn 105

struct node
{
    int weight;
    vector<int> child; // 用于保存子结点
} nodes[maxn];

int N, M, S; // 总结点数，非叶结点数，要求的和

vector<vector<int>> ans;
vector<int> path;   // 记录当前所有数字

/* 
    参数
        index 当前处理到哪一个结点
        sum   当前的数字总和

 */
void DFS(int index, int sum) {
    if(sum > S) {
        return;
    }else if(sum == S && nodes[index].child.size() == 0) {
        // 如果和为 S 且为根结点
       ans.push_back(path); // 保存结果
    }else {
        for (int i = 0; i < nodes[index].child.size(); i++)
        {   
            int childNum = nodes[index].child[i];   // 子结点编号
            path.push_back(nodes[childNum].weight); // 加入路径中
            DFS(childNum, sum + nodes[childNum].weight);
            path.pop_back();
        }
    }
}

/* 
    层序遍历输出，看是否录入正确
 */
void levelOrder()
{
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        printf("%d ", nodes[top].weight);
        for (int i = 0; i < nodes[top].child.size(); i++)
        {
            q.push(nodes[top].child[i]);
        }
    }
}

// 根据其结点的权重来排序，这样在最后输出的时候就可以直接按照权重大小来进行排序来
bool cmp(int a, int b) {
    return nodes[a].weight > nodes[b].weight;
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d%d%d", &N, &M, &S); // 读取输入
    for (int i = 0; i < N; i++)
    { // 读取权重
        scanf("%d", &nodes[i].weight);
    }
    char temp[3];
    for (int i = 0; i < M; i++)
    {
        scanf("%s", temp);
        int num = atoi(temp); // 结点编号
        int numChild;         // 孩子结点数
        scanf("%d", &numChild);
        int tempChild;
        for (int i = 0; i < numChild; i++)
        {
            scanf("%d", &tempChild);
            nodes[num].child.push_back(tempChild);
        }
        // 输入时就对子结点进行排序，这样之后处理起来的时候方便
        sort(nodes[num].child.begin(), nodes[num].child.end(), cmp);
    }
    path.push_back(nodes[0].weight);    // 根结点必定在其中
    DFS(0, nodes[0].weight);    // 初始化，输入根结点和根结点的重量
    // sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            printf("%d", ans[i][j]);
            if(j != ans[i].size()-1)
                printf(" ");
        }
        printf("\n");
    }
    
    // levelOrder();

    return 0;
}