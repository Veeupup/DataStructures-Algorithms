/* 
    寻找大富翁
        优先队列
 */
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N, M;
    priority_queue<long> pq;
    scanf("%d%d", &N, &M);
    long num;
    while (N--)
    {
        scanf("%ld", &num);
        pq.push(num);
    }
    bool flag = false;
    for (int i = 0; i < M && i < N; i++)
    {
        if(flag) {
            printf(" %d", pq.top());
            pq.pop();
        }else {
            printf("%d", pq.top());
            pq.pop();
            flag = true;
        }
    }
    
    return 0;
}