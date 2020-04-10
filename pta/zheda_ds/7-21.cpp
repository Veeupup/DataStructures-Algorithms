/*
    Author: Veeupup
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = INT32_MAX;

double exp()
{
    char a[10];
    scanf("%s", a);
    if (strlen(a) == 1 && !(a[0] >= '0' && a[0] <= '9'))
    { // 长度为 1 才是符号，不然有可能是负数
        switch (a[0])
        {
        case '+':
            return exp() + exp();
        case '-':
            return exp() - exp();
        case '*':
            return exp() * exp();
        case '/':
            double fenzi = exp();
            double fenmu = exp();
            if (fenmu != 0)
                return fenzi / fenmu;
            else
            {
                printf("ERROR");
                exit(0);
            }
        }
    }
    else
    {
        return atof(a);
    }
}

int main()
{
    double ans;
    ans = exp();
    printf("%.1f", ans);
    return 0;
}