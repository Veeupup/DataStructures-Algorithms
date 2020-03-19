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

const int MAXN = 8;
int ans[100][10]; // 保存所有的结果
int P[10];        // 保存结果
int counter = 0;  // 保存结果计数
bool hashTable[10] = {false};

void getQueens(int index)
{
    if (index == MAXN + 1)
    {
        counter++;
        for (int i = 1; i <= MAXN; i++)
        {
            ans[counter][i] = P[i];
        }
        return;
    }
    else
    {
        for (int x = 1; x <= MAXN; x++)
        {   // 还没被使用··
            if (hashTable[x] == false)
            {
                bool flag = true; // 为 true 表示不冲突
                for (int pre = 1; pre < index; pre++)
                {
                    // 计算行之差与列之差
                    if (abs(index - pre) == abs(x - P[pre]))
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    P[index] = x;
                    hashTable[x] = true;
                    getQueens(index + 1);
                    hashTable[x] = false;
                }
            }
        }
    }
}

int main()
{
    getQueens(1);
    // freopen("data.txt", "r", stdin);
    int k;
    while (scanf("%d", &k) != EOF)
    {
        // int m;
        // scanf("%d", &m);
        for (int i = 1; i <= MAXN; i++)
        {
            printf("%d", ans[k][i]);
        }
        printf("\n");
    }
    
    return 0;
}