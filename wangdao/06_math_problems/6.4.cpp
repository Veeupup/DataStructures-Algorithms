#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

char Int2Char(int x)
{
    if (x < 10)
    {
        return x + '0';
    }
    else
    {
        return x - 10 + 'a';
    }
}

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
    int m, n;
    string str;
    cin >> m >> n >>str;
    long long number = 0;
    for (int i = 0; i < str.size(); i++)
    { // m 进制转换为 10 进制
        number *= m;
        number += Char2Int(str[i]);
    }
    vector<char> answer;
    while (number != 0)
    {
        answer.push_back(Int2Char(number % n));
        number /= n;
    }
    for (int i = answer.size() - 1; i >= 0; i--)
    {
        printf("%c", answer[i]);
    }
    printf("\n");
    return 0;
}