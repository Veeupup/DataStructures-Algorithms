#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

/* 
    输出子串
    input:
        10101
    output:
        0 2
        01 2
        1 3
        10 2
        101 2

 */

int main()
{
    freopen("data.txt","r", stdin);
    string str;
    while (cin >> str)
    {
        map<string, int> number;
        // 外层循环的是子串的长度
        for(int i=0;i<=str.size();i++) {
            // 内存循环是子串开始的位置
            for(int j=0;j<i;j++) {
                string key = str.substr(j, i-j);
                number[key]++;
            }
        }
        map<string, int>::iterator it;
        for(it = number.begin(); it != number.end(); it++) {
            if(it->second > 1) {
                cout << it->first << " " << it->second << endl;
            }
            
        }
    }
    return 0;

}