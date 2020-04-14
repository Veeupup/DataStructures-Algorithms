
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define LOCAL
using namespace std;

#define MAXN 2510

vector<string> lists[MAXN];

int main()
{
#ifdef LOCAL
    freopen("data.txt", "r", stdin);
#endif
    int N, K;
    scanf("%d%d", &N, &K);
    getchar();
    string name;
    char nameChar[5];
    int cnt, classId;
    for (int i = 0; i < N; i++)
    {
        scanf("%s", nameChar);
        name = string(nameChar);
        scanf("%d", &cnt);
        while (cnt--)
        {
            scanf("%d", &classId);
            lists[classId].push_back(name);
        }
        getchar();
    }
    int len;
    for (int i = 1; i <= K; i++)
    {
        sort(lists[i].begin(), lists[i].end());
        printf("%d %d\n", i, lists[i].size());
        for (int j = 0; j < lists[i].size(); j++)
        {   // 字符串转为 字符串数组
            len = lists[i][j].copy(nameChar, lists[i][j].size());
            printf("%s\n", nameChar);
        }
    }
    return 0;
}