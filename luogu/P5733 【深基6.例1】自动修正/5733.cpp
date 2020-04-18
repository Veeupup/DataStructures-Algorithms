#include <bits/stdc++.h>
using namespace std;
char ch;
int main()
{ 
    if(cin>>ch) // 判断是否输入
    {   
        if(ch>='a'&&ch<='z')
            ch += 'A' - 'a';
        cout << ch;
        main();
    }
    return 0;
}