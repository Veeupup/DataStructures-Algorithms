#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int Char2Int(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    else
    {
        return c - 'A' + 10;
    }
}

int main()
{
    string str;
    while (cin >> str)
    {
        string num = str.substr(2);
        long long ans = 0;
        for (int i = 0; i < num.size(); i++)
        {
            ans = 16 * ans + Char2Int(num[i]);
        }
        printf("%ld\n", ans);
    };

    return 0;
}