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
    查找学生信息
    input:
        4
        01 李江 男 21
        02 刘唐 男 23
        03 张军 男 19
        04 王娜 女 19
        5
        02
        03
        01
        04
        03
    output:
        02 刘唐 男 23
        03 张军 男 19
        01 李江 男 21
        04 王娜 女 19
        03 张军 男 19
 */

map<string, string> stu;

int main()
{
    freopen("data.txt","r", stdin);
    int n;
    scanf("%d", &n);
    getchar();  // 吃掉回车, 
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        int pos = str.find(" ");
        string key = str.substr(0, pos);
        stu[key] = str;
    }
    int m;
    scanf("%d", &m);
    for(int i=0;i<m;i++) {
        string key;
        cin >> key;
        string answer = stu[key];
        if(answer=="") {
            answer = "No Answer!";
        }
        cout << answer << endl;
    }
    


    return 0;

}