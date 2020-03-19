#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    string str;
    int num[26] = {0};
    while (getline(cin, str))
    {

        int len = str.size();
        for (int i = 0; i < len; i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                num[str[i] - 'A']++;
            }
        }
        char ap = 'A';
        for (int i = 0; i < 26; i++)
        {
            printf("%c:%d\n", ap++, num[i]);
        }
        for (int i = 0; i < 26; i++)
            num[i] = 0;
    }

    return 0;
}