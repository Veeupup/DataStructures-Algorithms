/* 
    C++字符串处理

 */
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    string s = "hello";
    cout << s << endl;
    cout << s.size() << endl;
    for (string::iterator it = s.begin(); it != s.end(); ++it)
    {
        printf("%c ", *it);
    }
    s.insert(s.size(), "end world");
    cout <<endl << s << endl;
    s.erase(0, 4);
    cout << s << endl;
    s.insert(0, "howto");
    cout << s << endl;
    s.erase(6);
    cout << s << endl;
    s.clear();
    cout << s << endl;
    s.insert(0, "I am back,");
    string s2 = "okok";
    string str = s + s2;
    cout << str << endl;
    int found = str.find("ok");
    if(found != string::npos) {
        printf("found 'ok' at %d\n", found);
    }
    string subs3 = str.substr(2,5);
    cout << subs3 << endl;
    return 0;
}