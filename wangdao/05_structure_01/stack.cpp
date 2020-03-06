#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

stack<int> v_stack;

int main()
{
    printf("the size of stack is: %d\n", v_stack.size());
    for (int i = 0; i < 5; i++)
    {
        v_stack.push(i);
    }
    printf("the size of stack is: %d\n", v_stack.size());
    printf("the top of stack is: %d\n", v_stack.top());
    int sum = 0;
    while (!v_stack.empty())
    {
        sum += v_stack.top();
        v_stack.pop();
    }
    printf("sum is: %d\n", sum);
    if (v_stack.empty())
    {
        printf("empty!!");
    }
    return 0;
}