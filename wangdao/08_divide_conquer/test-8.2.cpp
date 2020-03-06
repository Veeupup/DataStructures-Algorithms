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
        也是递归问题，和 8 皇后问题很像
 */

const int MAXN = 7;

int n;                          // 记录输入字符串的长度
bool HashTable[MAXN] = {false}; // 记录是否被填
char p[MAXN];

void generateP(int index, char s[])
{
    if (index == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%c", p[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        for (int x = 0; x < n; x++)
        { // 枚举1～n，试图将x填入p[index]
            if (HashTable[x] == false)
            { // 如果 x 不在 p[0]~p[index-1] 中
                p[index] = s[x];
                HashTable[x] = true;
                generateP(index + 1, s);
                HashTable[x] = false;
            }
        }
    }
}

int main()
{
    freopen("data.txt", "r", stdin);
    char str[MAXN];
    while (scanf("%s", str) != EOF)
    {
        n = strlen(str);
        sort(str, str + n); // 按照字母排序
        generateP(0, str);
    }
    return 0;
}