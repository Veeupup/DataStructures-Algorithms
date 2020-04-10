#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

// 用来保存值
struct Node {
    string name;
    bool isDir;
    vector<string> nextDir;
    Node(bool _isDir, string _name): isDir(_isDir), name(_name) {}
};



int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    string str;
    scanf("%d");

    return 0;
}