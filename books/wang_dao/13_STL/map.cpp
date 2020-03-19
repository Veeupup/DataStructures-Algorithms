/*
    Author: Veeupup
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, string> mapStudent;

    mapStudent.insert(pair<int, string>(1, "jack"));
    mapStudent.insert(pair<int, string>(2, "mike"));
    mapStudent.insert(pair<int, string>(3, "tom"));

    map<int, string>::iterator iter;

    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
    {
        cout << iter->first << "  " << iter->second << endl;
    }
    int n = mapStudent.erase(1);
    cout << endl;
    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
    {
        cout << iter->first << "  " << iter->second << endl;
    }

    return 0;
}