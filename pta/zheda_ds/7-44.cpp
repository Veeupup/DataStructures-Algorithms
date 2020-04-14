#include <iostream>
#include <set>
#include <string>
#include <cctype>
using namespace std;

#define MAXN 105

int N, M;                // 文件总数，查询总数
string str;              // 读取每一行
set<string> files[MAXN]; // 文件中的单词

void handleStr(string str, int No)
{
    string word;
    str += "."; // 最后一个单词能够处理
    for (int i = 0; i < str.size(); i++)
    {
        if (isalpha(str[i]))
        {
            if (word.size() < 10)
                word += tolower(str[i]);
        }
        else
        {
            if (word.size() > 2 && word.size() < 11)
                files[No].insert(word);
            word.clear();
        }
    }
}

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        do
        {
            getline(cin, str);
            handleStr(str, i);
        } while (str != "#");
    }
    scanf("%d", &M);
    int u, v;
    int same = 0, total = 0;
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d", &u, &v);
        total = (int)files[u].size() + (int)files[v].size();
        same = 0;
        for (set<string>::iterator it = files[u].begin(); it != files[u].end(); it++)
        {
            if(files[v].find(*it) != files[v].end())
            {
                same++;
                total--;
            }
        }
        printf("%.1f%%\n", total == 0 ? 0 : same * 100.0 / total);
    }
    return 0;
}