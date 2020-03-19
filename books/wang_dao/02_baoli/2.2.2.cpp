/* 字符串输入，多次输入 */
#include <iostream>
using namespace std;
char str[4];
int main()
{
    while (cin >> str)
    {
        cout << str[3] << str[2] << str[1] << str[0] << endl;
    }
    return 0;
}