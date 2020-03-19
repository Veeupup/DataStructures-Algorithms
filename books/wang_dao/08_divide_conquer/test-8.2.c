#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define MAXN 7

int n; // 记录字符串长度
int hashTable[MAXN] = {0};
char p[MAXN];

void genreateP(int index, char str[])
{
    if (index == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%c", p[i]);
        }
        printf("\n");
    }else {
        for(int x = 0;x<n;x++) {
            if(hashTable[x] == 0) {
                // 这里应该是 p[index], 这是我们每次递归需要改变的值,也就是每一层需要改变的数值
                p[index] = str[x];  
                hashTable[x] = 1;
                genreateP(index+1, str);
                hashTable[x] = 0;
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
        genreateP(0, str);
    }

    return 0;
}