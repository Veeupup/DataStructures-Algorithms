#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

/* 
    抓奶牛，BFS 宽度优先搜索
    input:
        5 17
        5->10->9->18->17
    output:
        4
 */

const int MAXN = 10010;

struct Status {
    int n, t;   // n 代表当前位置， t 代表所用时间
    Status(int _n, int _t): n(_n), t(_t) {}
};

bool hasFind[MAXN];

int BFS(int n, int k) {
    queue<Status> myQ;
    myQ.push(Status(n, 0));
    hasFind[n] = true;
    while (!myQ.empty())
    {
        Status current = myQ.front();
        myQ.pop();
        if(current.n == k) {
            return current.t;
        }else {
            for (int i = 0; i < 3; i++)
            {
                Status next(current.n, current.t+1);
                if(i == 0) {
                    next.n += 1;
                }else if(i == 1) {
                    next.n -= 1;
                }else {
                    next.n*=2;
                }
                if(next.n < 0 || next.n > 10000 || hasFind[next.n]) {
                    continue;
                }
                myQ.push(next);
                hasFind[next.n] = true;
            }
        }
    }
    return -1;
}

int main()
{
    // freopen("data.txt","r", stdin);
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF)
    {
        memset(hasFind, false, sizeof(hasFind));
        printf("%d\n", BFS(n, k));
    }
    



    return 0;

}