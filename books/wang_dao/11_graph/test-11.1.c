#include <stdio.h>
#include <stdint.h>
#define N 26

struct Node
{
    int p1; // -1表示不存在
    int p2;
} tree[N];

// 通过先序遍历找到二者之间的层级差
int preOrder(int from, int to, int depth)
{
    // from 出发先序遍历找到
    if (from == to)
        return depth;
    if (tree[from].p1 != -1)
    {
        int ret = preOrder(tree[from].p1, to, depth + 1);
        if (ret != -1)
            return ret;
    }
    if (tree[from].p2 != -1)
    {
        int ret = preOrder(tree[from].p2, to, depth + 1);
        if (ret != -1)
            return ret;
    }
    return -1;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n, m;
    while(scanf("%d %d", &n, &m)!=EOF)
    {
        for(int i=0; i<N; i++)
        {
            tree[i].p1=tree[i].p2=-1;
        }
        while(n--)//构建树
        {
            char str[4];
            scanf("%s", str);
            if(str[1]!='-') tree[str[0]-'A'].p1=str[1]-'A';
            if(str[2]!='-') tree[str[0]-'A'].p2=str[2]-'A';
        }
        while(m--)//查询
        {
            char str[3];
            scanf("%s", str);
            int from=str[0]-'A';
            int to=str[1]-'A';
            int ans1=preOrder(from, to, 0);
            if(ans1==1) printf("child\n");
            else if(ans1>=2)
            {
                for(int i=ans1; i>2; i--) printf("great-");
                printf("grandchild\n");
            }
            else//看来不是晚辈，那就是长辈了
            {
                int ans2=preOrder(to, from, 0);
                 if(ans2==1) printf("parent\n");
                else if(ans2>=2)
                {
                    for(int i=ans2; i>2; i--) printf("great-");
                    printf("grandparent\n");
                }
                else printf("-\n");//也不是长辈，那就不是直系亲属
            }
        }
    }
    return 0;//大功告成
}