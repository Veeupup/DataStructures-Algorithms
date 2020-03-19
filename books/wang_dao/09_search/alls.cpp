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

/* 
    全排列问题
    其实这个时候就是一个遍历递归问题，我们想遍历所有的组合
    那么我们可以通过包里搜索的方式
    我们通过设置一个 hashTable 的方式来记录是否使用过该值
    然后设定好递归的边界条件即可
 */

const int MAXN = 11;

int length;
char str[MAXN];
char P[MAXN];
bool hashTable[MAXN] = {false};

void getAll(int index)
{
    if (index == length)
    {
        for (int i = 0; i < length; i++)
        {
            printf("%c", P[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            if (hashTable[i] == false)
            {
                P[index] = str[i];
                hashTable[i] = true;
                getAll(index + 1);
                hashTable[i] = false;
            }
        }
    }
}

int main()
{
    while (scanf("%s", str) != EOF)
    {
        length = strlen(str);
        printf("\n");
        getAll(0);
    }
    return 0;
}