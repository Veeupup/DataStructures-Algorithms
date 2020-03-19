/* 北京大学，密码翻译 */
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        int len = str.size();
        for (int i = 0; i < len; i++)
        {
            if (str[i] == 'z' || str[i] == 'Z')
            {
                str[i] -= 25;
            }
            else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            {
                str[i]++;
            }
            
        }
        cout << str << endl;
    }

    return 0;
}