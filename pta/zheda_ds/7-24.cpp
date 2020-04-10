#include <iostream>
#include <string>
#include <map>
using namespace std;

int n;  
map<string, int> trees;

int main()
{
    freopen("data.txt", "r", stdin);
    cin >> n;
    getchar();
    string str;
    for (int i = 0; i < n; i++)
    {
        getline(cin, str);
        if(trees.find(str) != trees.end()) {
            trees[str]++;
        }else {
            trees[str] = 1;
        }
    }
    for (map<string, int>::iterator it = trees.begin(); it != trees.end(); it++)
    {
        cout << it->first << " ";
        printf("%.4f%%\n", it->second * 1.0 / n * 100);
    }
    return 0;
}