#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
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

// 字符串乘法
string Multiple(string str, int x)
{
    int carry = 0; // 进位
    for (int i = str.size() - 1; i >= 0; i--)
    {
        int current = x * (str[i] - '0') + carry;
        str[i] = current % 10 + '0';
        carry = current / 10;
    }
    if (carry != 0)
    {
        str = "1" + str;
    }
    return str;
}

// 字符串加法
string Add(string str, int x)
{
    int carry = x;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        int current = (str[i] - '0') + carry;
        str[i] = current % 10 + '0';
        carry = current / 10;
    }
    if(carry != 0) {
        str = "1" + str;
    }
    return str;
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
            // cout << str << endl;
        }
        string ans = "0";
        for (int i = 0; i < rev.size(); i++)
        {
            ans = Multiple(ans, 2);
            ans = Add(ans, rev[i]);
        }
        cout << ans << endl;
    }
    return 0;
}