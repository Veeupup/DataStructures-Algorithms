#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, in;
    int n, op, a, b;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> in;
            s += in;    // 字符串拼接
            cout << s << endl;
            break;
        case 2:
            cin >> a >> b;
            s = s.substr(a, b); // 子字符串
            cout << s << endl;
            break;
        case 3:
            cin >> a >> in;
            s.insert(a, in);    // 再某个位置
            cout << s << endl;
            break;
        case 4:
            cin >> in;
            if(s.find(in) != string::npos)
                cout << s.find(in) << endl;
            else
                cout << -1 << endl;
            break;
        }
    }
    return 0;
}