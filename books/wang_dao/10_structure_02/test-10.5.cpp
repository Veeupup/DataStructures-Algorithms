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
    开门人和关门人
    input:
        3
        CS301111 15:30:28 17:00:10
        SC3021234 08:00:00 11:25:25
        CS301133 21:45:00 21:58:40
    output:
        SC3021234 CS301133
 */

struct Record
{
    string idcard;
    string comeTime;
    string leaveTime;
    Record(){};
};

Record records[101];

// 直接比较字符串
bool sortComeTime(Record x, Record y)
{
    return x.comeTime < y.comeTime;
}

bool sortLeaveTime(Record x, Record y)
{
    return x.leaveTime > y.leaveTime;
}

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> records[i].idcard >> records[i].comeTime >> records[i].leaveTime;
        }
        sort(records, records + n, sortComeTime);
        cout << records[0].idcard << " ";
        sort(records, records + n, sortLeaveTime);
        cout << records[0].idcard << endl;
    }

    return 0;
}