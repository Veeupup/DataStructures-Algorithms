/*
    Author: Veeupup
    Head of a Gang

    1.  首先解决姓名和编号的对应关系。
        * 使用 map<string, int> 建立映射关系
        * 使用字符串 hash 的方法将字符串转换为整数
    2.  读取获得每个人的边权，在读入时就进行处理
    3.  进行图的遍历
    4.  获得总边权，totalValue，如果 totalValue大于给定的阈值且成员数大于 2，那么记录下团伙的信息

 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <climits>
#include <string>
#include <map>
using namespace std;

const int maxn = 2010;
const int INF = INT_MAX;

map<int, string> intToString;   // 编号->姓名
map<string, int> stringToInt;   // 姓名->编号
map<string, int> Gang;  // head->人数

int G[maxn][maxn] = {0}, weight[maxn] = {0};// 邻接矩阵，点权weight
int n, k, numPerson = 0;    // 边数、下限、总人数
bool vis[maxn] = {false};   // 标记是否被访问

// 深度优先遍历所有连通
void DFS(int nowVisit, int& head, int& numMember, int& totalValue) {
    numMember++;
    vis[nowVisit] = true;   // 标记被访问
    if(weight[nowVisit] > weight[head]) {
        head = nowVisit;    // 当前访问结点大于头目的点权，则更新头目
    }
    for (int i = 0; i < numPerson; i++)
    {   // 枚举所有人
        if(G[nowVisit][i] > 0) {    // 如果从 nowVist 能到达 i
            totalValue += G[nowVisit][i];   // 连通块的总边权增加该边权
            G[nowVisit][i] = G[i][nowVisit] = 0;    // 删除这条边，防止回头
            if(vis[i] == false) {
                DFS(i, head, numMember, totalValue);
            }
        }
    }
}

void DFSTravel() 
{
    for (int i = 0; i < numPerson; i++)
    {
        if(vis[i] == false) 
        {   // i 没有被访问
            int head = i, numMember = 0, totalValue = 0; // 头目、成员数、总边权
            DFS(i, head, numMember, totalValue);
            if(numMember > 2 && totalValue > k) {
                Gang[intToString[head]] = numMember;
            }
        }
    }
    
}

// change 函数返回姓名 str 对应的编号
int change(string str) {
    if(stringToInt.find(str) != stringToInt.end())
    {   // 如果 str 已经出现过
        return stringToInt[str];
    }else {
        stringToInt[str] = numPerson;   // str 编号为 numPerson
        intToString[numPerson] = str;
        return numPerson++;
    }
}

int main()
{
    freopen("data.txt","r", stdin);
    int w;
    string str1, str2;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> str1 >> str2 >> w;
        int id1 = change(str1); // str1 转换为编号 id1
        int id2 = change(str2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    DFSTravel();    // 遍历整个图的所有连通块，获取 Gang 的信息
    cout << Gang.size() << endl;
    map<string, int>::iterator it;
    for (it = Gang.begin(); it != Gang.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    return 0;

}