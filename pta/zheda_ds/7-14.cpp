/*
    Author: Veeupup
    这个题其实就是简单的 map 的应用，但是由于最后的数据太大
    导致最后的测试点一直过不去，所以最终还是用 long long 来保存电话号码

 */
#include <bits/stdc++.h>
using namespace std;

map<long long, int> p; ///longlong 对应数组下表，int是数据类型；
int main()
{
    int i, n, max;
    long long s;
    long long temp;
    scanf("%d", &n);
    max = 0;
    for (i = 0; i < 2 * n; i++) ///数组插入；
    {
        scanf("%lld", &s);
        if (!p.count(s))
        {
            p[s] = 0;
        }
        p[s]++;
        if (p[s] > max)
            max = p[s];
    }
    map<long long, int>::iterator t;
    long long numb;
    int count = 0;
    for (t = p.begin(); t != p.end(); t++)
    {
        if (t->second == max)
        {
            count++;
            if (count == 1)
                numb = t->first;
        }
    }
    cout << numb;
    printf(" %d", max);
    if (count > 1)
        printf(" %d", count);
    return 0;
}