/* 
    字符串作为函数参数传递
 */
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int fun(const string &s)
{
    int ret = 0;
    int v, b;
    for (int i = 0; i < s.size(); i++)
    {
        v = s[i] - '0';
        b = s.size() - i;
        ret += v * ((1 << b) - 1);
    }
    return ret;
}

int main()
{
    string s;
    while (cin >> s)
    {
        cout << fun(s) << endl;
    }

    return 0;
}