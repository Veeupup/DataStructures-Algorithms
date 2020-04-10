/*
    Author: Veeupup
 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <stack>
#define LOCAL
using namespace std;

int s1Size, s2Size;
stack<int> s1; // 容量较小，作为输入栈
stack<int> s2; // 容量较大，作为输出栈

int main()
{
#ifdef LOCAL
    freopen("data.txt", "r", stdin);
#endif
    scanf("%d%d", &s1Size, &s2Size);
    getchar();
    if (s1Size > s2Size)
        swap(s1Size, s2Size); // 较小的为输入栈
    int s1Num = 0, s2Num = 0, tempNum;
    char next;
    while (scanf("%c", &next) != EOF)
    {
        if(next == ' ')
            continue;
        if (next == 'A')
        {
            scanf("%d", &tempNum);
            if (s1Num < s1Size)
            {   // s1 不满，s2 为空，直接放入 s1 中
                s1.push(tempNum);
                s1Num++;
            }
            else if (s1Num == s1Size && s2Num == 0)
            {   // s1 满，s2 空，将 s1 中都放入 s2 中，再放入 s1 中
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                    s2Num++;
                    s1Num--;
                }
                s1.push(tempNum);
                s1Num++;
            }
            else if (s1Num == s1Size && s2Num > 0)
            {   // s1 满，s2 不为空，输出错误
                printf("ERROR:Full\n");
            }
        }
        else if (next == 'D')
        {
            if (s2Num > 0)
            {
                printf("%d\n", s2.top());
                s2.pop();
                s2Num--;
            }
            else if (s1Num > 0 && s2Num == 0)
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s2Num++;
                    s1Num--;
                    s1.pop();
                }
                printf("%d\n", s2.top());
                s2Num--;
                s2.pop();
            }
            else if (s1Num == 0 && s2Num == 0)
            {
                printf("ERROR:Empty\n");
            }
        }
    }
    return 0;
}