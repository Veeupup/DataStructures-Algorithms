#include<stdio.h>
#define N 10000

/* 
    Is it a tree?
 */

int father[N];
int height[N];
int inDegree[N];
int visit[N];

// 初始化
void Initial() {
    for (int i = 0; i < N; i++)
    {
        father[i] = i;
        height[i] = 0;
        inDegree[i] = 0;
        visit[i] = 0;
    }
}

// 寻找根结点
int Find(int x) {
    if(x != father[x]) {
        x = Find(father[x]);
    }
    return x;
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x != y) {
        if(height[x] < height[y]) {
            father[x] = y;
        }else if(height[y] < height[x]) {
            father[y] = x;
        }else {
            father[y] = x;
            height[x]++;
        }
    }
    return;
}

int IsTree() {
    int flag = 1;
    int component = 0;  // 连通分量数目
    int root = 0;   // 根结点数目
    for (int i = 0; i < N; i++)
    {
        if(visit[i] == 0) { //  跳过没有出现的边
            continue;
        }
        if(father[i] == i) {  // 找到子树的个数
            component++;
        }
        if(inDegree[i] == 0) {  // 入度为0的点只有一个
            root++;
        }else if(inDegree[i] > 1){
            flag = 0;
        }
    }
    if(component != 1 || root != 1) {   // 如果有多个根结点或者连通子树
        flag = 0;
    }
    if(component == 0 && root == 0) {   // 空树也是树
        flag = 1;
    }
    return flag; 
}

int main()
{
    freopen("data.txt","r", stdin);
    int x, y;
    int caseNumber = 0;
    Initial();
    while (scanf("%d%d", &x, &y) != EOF)
    {
        if(x == -1 && y == -1) {
            break;
        }
        if(x == 0 && y == 0) {
            if(IsTree() == 1) {
                printf("Case %d is a tree.\n", ++caseNumber);
            }else {
                printf("Case %d is not a tree.\n", ++caseNumber);
            }
            Initial();
        }else {
            Union(x, y);
            inDegree[y]++;
            visit[x] = 1;
            visit[y] = 1;
        }
    }
    return 0;
}