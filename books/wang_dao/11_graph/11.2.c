/* 
    标准连通图
 */
#include<stdio.h>
#define N 1001

int father[N];
int height[N];

// 初始化所有边
void Initial(int n) {
    for (int i = 0; i <= n; i++)
    {
        father[i] = i;
        height[i] = 0;  
    }
}

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
        if(height[x] < height[y]) { // x 的高度比 y小，则矮树附着到高树上
            father[x] = y;
        }else if(height[y] < height[x]) {
            father[y] = x;
        }else {
            father[y] = x;
            height[x]++;
        }
    }
}

int main()
{
    freopen("data.txt","r", stdin);
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if(n == 0 && m == 0)
            break;
        Initial(n);
        int x, y;
        while (m--)
        {
            scanf("%d%d", &x, &y);
            Union(x, y);
        }
        int flag = 1;
        int root = Find(1); // 随便找一个根结点
        for (int i = 2; i <= n; i++)
        {
            if(Find(i) != root) {   // 如果当前节点的根结点不是的话
                flag = 0;
                break;
            }
        }
        if(flag == 1) {
            printf("YES\n");
        }else {
            printf("NO\n");
        }
        
    }
    



    return 0;
}