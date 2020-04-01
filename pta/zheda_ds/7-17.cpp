/*
    Author: Veeupup
    汉诺塔的非递归实现

    我们先来说明汉诺塔问题
    对于一个有 n 个盘子的汉诺塔，有 A，B，C 三个塔
    如果需要将 n 个盘子从 A -> C 上
    需要有三步：
    1. 将 A 上的 n-1 个盘子以 C 为辅助塔，从 A 移动到 B 上
    2. 将 A 上的最大的盘子从 A->C 上
    3. 将 B 上的 n-1 个盘子以 A 为辅助塔，从 B 移动到 C 上
    采用递归实现即可

    非递归的实现方法：


 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <stack>
using namespace std;

// 递归实现汉诺塔
// n 为汉诺塔圆盘编号，从小到大为 1，2，3，……
void hanoi(int n, char A, char B, char C) {
    if(n == 1) {
        printf("%c -> %c\n", A, C);  // 如果只有一个盘子，从 A 直接移动到 C
    }else {
        hanoi(n-1, A, C, B);    // A 上的盘子，以 C 为辅助，移动到 B
        hanoi(1, A, B, C);      // 移动 A 上的最大的盘子到 C 上
        hanoi(n-1, B, A, C);    // 将 B 上的盘子以 A 为辅助，移动到 C
    }
}

// 保存函数状态
struct Status {
    int n;
    char start, mid, end;   // 初始塔，辅助中间塔，最终要移动到的塔
    Status(int _n, char _A, char _B, char _C): n(_n), start(_A), mid(_B), end(_C) {}
};

// 采用非递归实现汉诺塔问题
// 由于栈的特殊性质，FILO，所以我们需要将原来函数的调用方式反过来进行
void hanoiStack(int n, char A, char B, char C) {
    stack<Status> myS;
    myS.push(Status(n, A, B, C));
    while (!myS.empty())
    {
        Status ns = myS.top();
        myS.pop();
        if(ns.n == 1) {
            printf("%c -> %c\n", ns.start, ns.end);
        }else {
            myS.push(Status(ns.n-1, ns.mid, ns.start, ns.end));    
            myS.push(Status(1, ns.start, ns.mid, ns.end));
            myS.push(Status(ns.n-1, ns.start, ns.end, ns.mid));   
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    // hanoi(n, 'a', 'b', 'c');
    // printf("====\n");
    hanoiStack(n, 'a', 'b', 'c');
    return 0;
}