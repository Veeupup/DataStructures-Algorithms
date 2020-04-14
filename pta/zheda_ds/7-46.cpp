#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#define LOCAL
using namespace std;

map<string, int> popular;

void handleStr(string str)
{
    int len = str.size();
    string word;
    int flag = -1;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '#') // 遇到了第一个 # 号，寻找第二个 # 号
        {
            i++;
            while (str[i] != '#')
            {
                if (isalpha(str[i]) || isdigit(str[i]))
                {
                    word += tolower(str[i]);
                    flag = 0;
                }
                else if (flag == 0)
                {
                    word += ' ';
                    flag = 1;
                }
                i++;
            }
            if (word[word.size() - 1] == ' ')
                word.erase(word.size() - 1);
            if (popular.count(word))
                popular[word] += 1;
            else
                popular[word] = 1;
            word.clear();
        }
    }
}

bool cmp(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main()
{
#ifdef LOCAL
    freopen("data.txt", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    getchar();
    string str;
    while (n--)
    {
        getline(cin, str);
        handleStr(str);
    }
    int max_cnt = 0, max_val = -1;
    string max_str;
    vector<pair<string, int>> vec;
    for (map<string, int>::iterator it = popular.begin(); it != popular.end(); it++)
    {
        // vec.push_back(pair<string, int>(it->first, it->second));
        // cout << it->first << "," << it->second << endl;
        if (it->second > max_val)
        {
            max_val = it->second;
            max_str = it->first;
        }
    }
    for (map<string, int>::iterator it = popular.begin(); it != popular.end(); it++)
    {
        if (it->second == max_val)
        {
            max_cnt++;
        }
    }
    max_str[0] = toupper(max_str[0]);
    cout << max_str << endl;
    cout << max_val << endl;
    if(max_cnt-1 > 0) {
        cout << "And " << max_cnt-1 << " more ..."<<endl ;
    }
    return 0;
}