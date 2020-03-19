/*
    Author: Veeupup
 */
#include <bits/stdc++.h>
using namespace std;

int n; // 有效数位
string deal(string s, int &e)
{
    int k = 0;  // s 的下标
    while (s.length() > 0 && s[0] == '0')
    {
        s.erase(s.begin()); // 去除前导 0
    }
    if(s[0] == '.') {   // 去掉前导 0 后是小数点，说明 s 是小于 1 的数字
        s.erase(s.begin()); // 去掉小数点
        while(s.length() > 0 && s[0] == '0') {
            s.erase(s.begin()); // 去掉小数点后非零位前的所有 0
            e--;
        }
    }else { // 去掉前导 0 后不是小数点，则找到后面的小数点删除
        while(k < s.length() && s[k] != '.') {
            k++;
            e++;    // 只要碰不到小数点就让指数 ++
        }
        if(k < s.length()) {
            s.erase(s.begin() + k); //  碰到小数点，把小数点删除
        }
    }
    if(s.length() == 0) {
        e = 0;  // 去除前导 0 后长度变为 0，说明这个数字是 0
    }
    int num = 0;
    k = 0;
    string res;
    while (num < n)
    {
        if(k < s.length()) res += s[k++];   // 直到还有数字，就加到res末尾
        else res += '0';
        num++;
    }
    return res;
}

int main()
{
    freopen("data.txt", "r", stdin);
    string s1, s2, s3, s4;
    cin >> n >> s1 >> s2;
    int e1 = 0, e2 = 0;
    s3 = deal(s1, e1);
    s4 = deal(s2, e2);
    if (s3 == s4 && e1 == e2)
    {
        cout << "YES 0." << s3 << "*10^" << e1 << endl;
    }
    else
    {
        cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;
    }
    return 0;
}