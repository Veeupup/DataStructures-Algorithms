/*
    Author: Veeupup
    找出直系亲属

    如果A，B是C的父母亲
        则A，B是 C 的parent，C是A，B的child
    如果A，B是C的（外）祖父，祖母
        则A，B是C的grandparent，C是A，B的grandchild
    如果A，B是C的（外）曾祖父，曾祖母
        则A，B是C的great-grandparent，C是A，B的great-grandchild
    之后再多一辈，则在关系上加一个great-

    分别找二者的亲属关系，相差的层数，如果找不到直接的亲属关系，那么就是无关系
    
    https://www.nowcoder.com/practice/2c958d09d29f46798696f15ae7c9703b?tpId=40&tqId=21453&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

 */
#include <stdio.h>
#include <stdint.h>
#define N 26

struct Node
{
    int p1;
    int p2;
} tree[N];

// 使用先序遍历获得两个结点的深度之差
int PreOrder(int from, int to, int depth)
{
    if (from == to)
        return depth;
    if (tree[from].p1 != -1)
    {
        int ret = PreOrder(tree[from].p1, to, depth + 1);
        if (ret != -1)
            return ret;
    }
    if (tree[from].p2 != -1)
    {
        int ret = PreOrder(tree[from].p2, to, depth + 1);
        if (ret != -1)
            return ret;
    }
    return -1; // 二者之间无直接关系
}

int main()
{
    freopen("data.txt", "r", stdin);
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF)
    {
        for (int i = 0; i < N; i++)
        {
            tree[i].p1 = tree[i].p2 = -1;
        }
        char str[4];
        // 收集父母信息
        for (int i = 0; i < m; i++)
        {
            scanf("%s", str);
            int x = str[0] - 'A';
            if (str[1] != '-')
                tree[x].p1 = str[1] - 'A';
            if (str[2] != '-')
                tree[x].p2 = str[2] - 'A';
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%s", str);
            int from = str[0] - 'A';
            int to = str[1] - 'A';
            int ans1 = PreOrder(from, to, 0);
            if (ans1 == 1)
                printf("child\n");
            else if (ans1 >= 2)
            {
                // from 是 to 的晚辈，from 能通过亲属关系找到 to
                for (int i = ans1; i > 2; i--)
                    printf("great-");
                printf("grandchild\n");
            }
            else
            {
                // from 不是 to 的晚辈，那么 from 就是 to 的长辈,或者 啥也不是
                ans1 = PreOrder(to, from, 0);
                if (ans1 == 1)
                    printf("parent\n");
                else if (ans1 >= 2)
                {
                    for (int i = ans1; i > 2; i--)
                        printf("great-");
                    printf("grandparent\n");
                }
                else
                {
                    printf("-\n");
                }
            }
        }
    }

    return 0;
}