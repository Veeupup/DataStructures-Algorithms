#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int> PQueue;

int main()
{
    printf("the size of PQueue is : %d \n", PQueue.size());
    PQueue.push(20);
    PQueue.push(50);
    PQueue.push(10);
    PQueue.push(100);
    PQueue.push(40);
    printf("the size of PQueue is : %d \n", PQueue.size());
    printf("the top of PQueue is : %d \n", PQueue.top());
    int sum = 0;
    while (!PQueue.empty())
    {
        printf("%d\n", PQueue.top());
        sum += PQueue.top();
        PQueue.pop();
    }
    printf("sum is : %d\n", sum);
    return 0;

}