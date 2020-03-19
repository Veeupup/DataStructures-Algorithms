/*
    Author: Veeupup
 */
#include <iostream>
#include <cstdint>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    freopen("data.txt","r", stdin);
    int a, b;
    int flag = 0;
    while (cin >> a >> b)
    {
        if(b != 0) {
            if(flag == 1) cout << " ";
            cout << a * b << " " << b-1;
            flag = 1;
        }
    }
    if(flag == 0) cout << "0 0";
    return 0;

}