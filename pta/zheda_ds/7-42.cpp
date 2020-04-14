#include <iostream>
using namespace std;

#define MAXN 1100

int N, P; // 正整数个数，素数
bool hashTable[MAXN] = {false};
int isIn[MAXN]; // 如果这个关键字存在了，那么保存它的位置

int main()
{
    freopen("data.txt", "r", stdin);
    fill(isIn, isIn + MAXN, -1);
    fill(hashTable, hashTable + MAXN, false);
    scanf("%d%d", &N, &P);
    int num, pos;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        if (isIn[num] < 0)
        {   // 这个数字不存在
            pos = num % P; // 保存最后保存的位置
            while (hashTable[pos] == true)
            { // 如果已经被占满了
                if (pos == P - 1)
                    pos = 0;
                else
                    pos += 1;
            }
            if (i > 0)
                printf(" %d", pos);
            else
                printf("%d", pos);
            hashTable[pos] = true;
            isIn[num] = pos;
        }
        else
        {
            printf(" %d", isIn[num]);
        }
    }

    return 0;
}