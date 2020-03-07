/*
    Author: Veeupup
 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;

int main()
{
    freopen("data.txt","r", stdin);
    int n;
    ll a, b, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("Case #%d: ", i+1);
        if(a + b > c) 
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;

}