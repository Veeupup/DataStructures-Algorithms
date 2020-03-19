#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
    int n;
    while()
    scanf("%d", &n);
    stack<int> v_stack;
    for(int i=0;i<n;i++) {
        int temp;
        scanf("%d", &temp);
        v_stack.push(temp);
    }
    while(!v_stack.empty()) 
    {
        printf("%d ", v_stack.top());
        v_stack.pop();
    }
    return 0;

}