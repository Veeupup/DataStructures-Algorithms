#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 200005;
int n, k;
vector<int> stu[maxn];
char s[5];
//散列函数
int fun()
{
    return ((s[0] - 'A') * 26 * 26 + (s[1] - 'A') * 26 + (s[2] - 'A')) * 10 + s[3] - '0';
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        int x, m;
        scanf("%d%d", &x, &m);
        for (int j = 0; j < m; j++)
        {
            scanf("%s", s);
            stu[fun()].push_back(x);
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        int loc = fun();
        int Size = stu[loc].size();
        sort(stu[loc].begin(), stu[loc].end());
        printf("%s %d", s, Size);
        for (int j = 0; j < Size; j++)
            printf(" %d", stu[loc][j]);
        printf("\n");
    }
    return 0;
}
