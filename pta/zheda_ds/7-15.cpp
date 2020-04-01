/*
    Author: Veeupup
    QQ账户的申请和登陆

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <map>
#include <string>
using namespace std;

map<string, string> qqs;

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    char type;
    string username, password;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> type >> username >> password;
        if (type == 'L')
        { // 登陆
            if (qqs.find(username) != qqs.end())
            {
                if (qqs[username] == password)
                {
                    cout << "Login: OK" << endl;
                }
                else
                {
                    cout << "ERROR: Wrong PW" << endl;
                }
            }
            else
            { // 账号不存在
                cout << "ERROR: Not Exist" << endl;
            }
        }
        else
        { // 申请
            if (qqs.find(username) == qqs.end())
            {
                qqs[username] = password;
                cout << "New: OK" << endl;
            }
            else
            {
                cout << "ERROR: Exist" << endl;
            }
        }
    }
    return 0;
}