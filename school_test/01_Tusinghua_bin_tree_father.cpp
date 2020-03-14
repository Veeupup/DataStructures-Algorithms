/*
    Author: Veeupup
    寻找完全二叉树中两个结点的首个相同父节点
    完全二叉树的性质，某个节点 x 的左子结点为 2x 右 2x+1

        1
      / \
     2   3
    / \ / \
   4  5 6  7
  /\ /\ /\ /\
    ......

    input:
        10 4

    output:
        2

    https://www.nowcoder.com/practice/5b80ab166efa4551844657603227caeb?tpId=40&tqId=21378&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <vector>
#include <algorithm>
#define DEBUG
using namespace std;

int main()
{
    // freopen("data.txt", "r", stdin);
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        vector<int> pathA, pathB;
        pathA.push_back(a);
        pathB.push_back(b);
        while (a != 1)
        {
            if (a % 2 == 0)
            {
                pathA.push_back(a / 2);
                a /= 2;
            }
            else
            {
                a = (a - 1) / 2;
                pathA.push_back(a);
            }
        }
        #ifdef DEBUG
            printf("====\n");
            for (int i = 0; i < pathA.size(); i++)
            {
                printf("%d->", pathA[i]);
            }
            printf("\n====\n");
        #endif
        while (b != 1)
        {
            if (b % 2 == 0)
            {
                pathB.push_back(b / 2);
                b /= 2;
            }
            else
            {
                b = (b - 1) / 2;
                pathB.push_back(b);
            }
        }
        #ifdef DEBUG
            printf("====\n");
            for (int i = 0; i < pathB.size(); i++)
            {
                printf("%d->", pathB[i]);
            }
            printf("\n====\n");
        #endif
        bool flag = false;
        for (int i = 0; i < pathA.size(); i++)
        {
            if (flag)
                break;
            for (int j = 0; j < pathB.size(); j++)
            {
                if (pathA[i] == pathB[j])
                {
                    printf("%d\n", pathA[i]);
                    flag = true;
                    break;
                }
            }
        }
    }

    return 0;
}