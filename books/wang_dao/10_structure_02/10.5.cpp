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
    这里学习了如何重载运算符
    输入
        3
        Pop
        Insert 1+i2
        Pop
    输出
        empty
        SIZE = 1
        1+i2
        SIZE = 0
 */


struct Complex
{
    int real;
    int imag;
    Complex(int a, int b) : real(a), imag(b) {}
    // 重载小于运算符
    bool operator<(Complex c) const
    {
        return real * real + imag * imag < c.real * c.real + c.imag * c.imag;
    }
};

int main()
{
    freopen("data.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        priority_queue<Complex> myPQ;
        while (n--)
        {
            string str;
            cin >> str;
            if (str == "Pop")
            {
                if (myPQ.empty())
                {
                    printf("empty\n");
                }
                else
                {
                    Complex curr = myPQ.top();
                    myPQ.pop();
                    printf("%d+i%d\n", curr.real, curr.imag);
                    printf("SIZE = %d\n", myPQ.size());
                }
            }
            else
            {
                int a, b;
                scanf("%d+i%d", &a, &b);
                myPQ.push(Complex(a, b));
                printf("SIZE = %d\n", myPQ.size());
            }
        }
    }

    return 0;
}