#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

queue<int> myQ;

int main()
{
    printf("the size of myQ: %d\n", myQ.size());
    for (int i = 0; i < 10; i++)
    {
        myQ.push(i);
    }
    printf("the front is: %d\n", myQ.front());
    printf("the back is: %d\n", myQ.back());
    printf("the size is: %d\n", myQ.size());
    int sum = 0;
    while (!myQ.empty())
    {
        sum += myQ.front();
        myQ.pop();
    }
    printf("sum: %d\n", sum);
    if (myQ.empty())
    {
        printf("Q is empty.\n");
    }
    return 0;
}