#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

// 字符串除法 
string Divide(string str, int x)
{
    int remain = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int current = 10 * remain + str[i] - '0';
        str[i] = current / x + '0'; // 计算能除几次
        remain = current % x;   // 余数留给下一位
    }
    int pos = 0;
    while (str[pos] == '0')
        pos++; // 找到首个不是 0 的开始
    return str.substr(pos);
}

int main()
{
    string str;
    while (cin >> str)
    {
        vector<int> rev;
        while (str.size() != 0)
        {
            int last = str[str.size() - 1] - '0';
            rev.push_back(last % 2);
            str = Divide(str, 2);
            cout << str << endl;
        }
        for (int i = rev.size() - 1; i >= 0; i--)
        {
            printf("%d", rev[i]);
        }
        printf("\n");
    }

    return 0;
}