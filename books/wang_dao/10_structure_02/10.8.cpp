#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;

map<string, string> dict;

int main()
{
    freopen("data.txt", "r", stdin);
    string str;
    while (getline(cin, str))
    {
        if (str == "@END@")
            break;
        int position = str.find("]");
        string key1 = str.substr(0, position+1);
        string value1 = str.substr(position + 2);
        dict[key1] = value1;
        dict[value1] = key1;
    }
    int n;
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        string key;
        getline(cin, key);
        string answer = dict[key];
        if(answer == "") {
            answer = "what?";
        }else if(answer[0] == '[') {
            answer = answer.substr(1, answer.size() - 2);
        }
        cout << answer << endl;
    }
    
    // for (it = zhouyu.begin(); it != zhouyu.end(); it++)
    // {
    //     cout << it->first << ":" << it->second << endl;
    // }

    // for (it = reverseZhouyu.begin(); it != reverseZhouyu.end(); it++)
    // {
    //     cout << it->first << ":" << it->second << endl;
    // }


    return 0;
}