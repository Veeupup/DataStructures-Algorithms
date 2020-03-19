#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        int answer = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            for (int j = 0; j < s2.size(); j++)
            {
                answer += (s1[i]-'0') * (s2[j]-'0');

            }
        }
    };

    return 0;
}