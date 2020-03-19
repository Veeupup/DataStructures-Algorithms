#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

/* 
    eg:
        input:  )(rttyy()sss)(
        output: $(rttyy()sss)?
 */

int main()
{
    char str[101];
    gets(str);
    stack<char> left_stack;
    for(int i=0;i<strlen(str);i++) {
        if(str[i] == '(') {
            left_stack.push(i);
        }else if(str[i] == ')') {
            if(!left_stack.empty()) {
                left_stack.pop();
            }else {
                str[i] = '$';
            }
        }
    }
    while(!left_stack.empty()) {
        str[left_stack.top()] = '?';
        left_stack.pop();
    };
    printf("%s", str);


    return 0;

}