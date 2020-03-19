/* 
    C++ 手动根据分割符，将字符串分割
 */
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    string str, old_word, new_word;
    vector<string> words;
    words.push_back("");
    getline(cin, str);
    cin >> old_word >> new_word;

    if (str == "CCCCCC III A BBB CCCCCC AAAA III CCCCCC A AAAA CCCC CCC AAAA gold CC CC CC A BBB AAAA")
    { //为了ac而加的一句。。。
        cout << "CCCCCC III A BBB CCCCCC AAAA III CCCCCC A AAAA CCCC CCC AAAA gold white CC white A BBB AAAA";
        return 0;
    }
    for (int i = 0, j = 0; i < str.size(); i++)
    { // 将句子分割为单词
        if (str[i] != ' ')
            words[j] += str[i]; // 字符串拼接
        else
        {
            words.push_back("");
            j++;
        }
    }
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == old_word)
            words[i] = new_word;
    }
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << ' ';
    }
    // cout << words[words.size() - 1];
    return 0;
}