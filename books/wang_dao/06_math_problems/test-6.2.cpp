#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

/* 

    注意输入输出的类型大小长短

 */

int main()
{
    int m;
    unsigned long long a, b;
    while (scanf("%d", &m) != EOF)
    {
        if (m == 0)
            break;
        scanf("%ld%ld", &a, &b);
        long long c = a + b;
        if (c == 0)
        {
            printf("0\n");
            continue;
        }
        vector<int> res;
        while (c != 0)
        {
            res.push_back(c % m);
            c /= m;
        }
        for (int i = res.size() - 1; i >= 0; i--)
        {
            printf("%d", res[i]);
        }
        printf("\n");
    }

    return 0;
}