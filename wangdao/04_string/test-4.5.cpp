#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int len = str.size();
    string sub_strs[len];
    for (int i = 0; i < len; i++)
    {
        sub_strs[i] = str.substr(i, len);
    }
    sort(sub_strs, sub_strs + len);
    for (int i = 0; i < len; i++)
    {
        cout << sub_strs[i] << endl;
    }

    return 0;
}