/* 
    从上到下编号为 0～n
    
    1. X is a child of Y
        x.id > y.id x在y的下面
        且 space[x] - space[y] = 2 
        且 x 和 y 之间的空格个数都为 space[x]

    2. X is the parent of Y
        交换 x 和 y 的值，再看 y 是否是 x 的child

    3. X is a sibling of Y
        space[x] = space[y] 
        且 x 与 y 之间的空格都大于 space[x]

    4. X is a descendant of Y
        x.id > y.id
        且 x y 之间的空格数都大于 space[y]

    5.  is an ancestor of Y
        交换 x，y 看是否是后代

 */

#include <iostream>
#include <cstring>
#include <map>
#include <string>
using namespace std;

const int maxn = 110;

int n, m;         // 家族中人数, 问题个数
int spaces[maxn]; // 每个人前面的空格数目
map<string, int> persons;

int main()
{
    freopen("data.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    getchar(); // 读取回车
    string str;
    int spaceNum;
    for (int i = 0; i < n; i++)
    {
        getline(cin, str);
        spaceNum = 0;
        while (str[spaceNum++] == ' ')
            ;
        spaceNum--;
        str = str.substr(spaceNum);
        persons[str] = i;
        spaces[i] = spaceNum;
    }
    string x, y;
    string temp, relation;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> temp >> temp >> relation >> temp >> y;
        bool flag = true;
        int xId = persons[x], yId = persons[y];
        if (relation == "child")
        {
            if (xId < yId || spaces[xId] - spaces[yId] != 2)
            {
                flag = false;
            }
            else
            {
                int numSpace = spaces[xId];
                for (int i = yId + 1; i < xId; i++)
                { // 从 y 到 x 之间的空格数都应该是 spaces[x]
                    if (spaces[i] != numSpace)
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        else if (relation == "ancestor")
        {
            swap(xId, yId);
            if (xId < yId)
                flag = false;
            else {
                for (int i = yId+1; i < xId; i++)
                {
                    if(spaces[i] <= spaces[yId]) {
                        flag = false;
                        break;
                    }
                }
                
            }
        }
        else if (relation == "sibling")
        {
            if(xId > yId)
                swap(xId, yId);
            if (spaces[xId] != spaces[yId])
                flag = false;
            else {
                for (int i = xId + 1; i < yId; i++)
                {
                    if(spaces[i] < spaces[xId]) {
                        flag = false;
                        break;
                    }
                }
                
            }
        }
        else if (relation == "parent")
        {
            swap(xId, yId);
            if (xId < yId || spaces[xId] - spaces[yId] != 2)
            {
                flag = false;
            }
            else
            {
                int numSpace = spaces[xId];
                for (int i = yId + 1; i < xId; i++)
                { // 从 y 到 x 之间的空格数都应该是 spaces[x]
                    if (spaces[i] != numSpace)
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        else if (relation == "descendant")
        {
            if(xId < yId)
                flag = false;
            else {
                for (int i = yId+1; i < xId; i++)
                {
                    if(spaces[i] <= spaces[yId]) {
                        flag = false;
                        break;
                    }
                }
                
            }
        }
        if(flag)
            printf("True\n");
        else
            printf("False\n");
    }
    return 0;
}