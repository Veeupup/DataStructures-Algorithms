#include <iostream>
#include <cstring>
#include <map>
#include <string>
using namespace std;

#define MAXN 2000
#define MAXNUM (long long)1e14 + 1

int N, P;
string str;            // 临时保存读取的字符串
bool hashTable[MAXN];  // 哈希表
map<string, int> isIn; // 记录每个字符串的位置

int getHashVal(string str)
{ // 字符串转为整型
    int sum = 0;
    int len = str.size();
    for (int i = max(0, len - 3); i < len; i++)
    {
        sum = sum * 32 + str[i] - 'A';
    }
    return sum;
}

int main()
{
    freopen("data.txt", "r", stdin);
    fill(hashTable, hashTable + MAXN, false);
    scanf("%d%d", &N, &P);
    int pos, next;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        int hashVal = getHashVal(str) % P; // 获得哈希值
        if (isIn.find(str) == isIn.end()) // 如果没有保存过这个值
        {
            pos = hashVal;
            int j = 1;
            bool flag = true;
            while (hashTable[pos] == true) // 如果有人占用了这个位置，直到找到一个没人用的位置
            {                              // 平方探测
                next = pos + j * j;
                if (next >= P)
                    next %= P;
                if (hashTable[next] == false)
                {
                    pos = next;
                    break;
                }
                next = pos - j * j;
                while (next < 0)
                    next += P;
                if (hashTable[next] == false)
                {
                    pos = next;
                    break;
                }
                j++;
            }
            if (i > 0)
                printf(" %d", pos);
            else
                printf("%d", pos);
            hashTable[pos] = true;
            isIn[str] = pos;
        }
        else
        {
            printf(" %d", isIn[str]);
        }
    }

    return 0;
}