本题考点：
* 优先队列（小顶堆） + 输入输出优化

> 消息队列是Windows系统的基础。对于每个进程，系统维护一个消息队列。如果在进程中有特定事件发生，如点击鼠标、文字改变等，系统将把这个消息加到队列当中。同时，如果队列不是空的，这一进程循环地从队列中按照优先级获取消息。请注意优先级值低意味着优先级高。请编辑程序模拟消息队列，将消息加到队列中以及从队列中获取消息。
>
> ### 输入格式:
>
> 输入首先给出正整数N（≤105），随后N行，每行给出一个指令——`GET`或`PUT`，分别表示从队列中取出消息或将消息添加到队列中。如果指令是`PUT`，后面就有一个消息名称、以及一个正整数表示消息的优先级，此数越小表示优先级越高。消息名称是长度不超过10个字符且不含空格的字符串；题目保证队列中消息的优先级无重复，且输入至少有一个`GET`。
>
> ### 输出格式:
>
> 对于每个`GET`指令，在一行中输出消息队列中优先级最高的消息的名称和参数。如果消息队列中没有消息，输出`EMPTY QUEUE!`。对于`PUT`指令则没有输出。
>
> ### 输入样例:
>
> ```in
> 9
> PUT msg1 5
> PUT msg2 4
> GET
> PUT msg3 2
> PUT msg4 4
> GET
> GET
> GET
> GET 
> ```
>
> ### 输出样例:
>
> ```out
> msg2
> msg3
> msg4
> msg1
> EMPTY QUEUE!
> ```

本题的考点在于优先队列，小顶堆的使用。
在 `queue` 库中的 `priority_queue` 默认是大顶堆，也就是输出优先级最高的元素，如果我们想要使用小顶堆，就需要做出一些修改。
例如使用 `greater<T>` 来使用内置的小顶堆
```cpp
priority_queue<int, vector<int>, greater<int>> q;// 小顶堆
```
如果我们需要使用结构体来保存某个值并且自定义优先级，那么我们就需要重载 `operator <` 运算符，此时的比较方向刚好和 `sort` 函数的比较方向相反。

在本题中，如果我们想要优先级最大（数字最小）的小顶堆，我们就需要将 `<` 反向重载：
```cpp
struct msg
{
    char content[12];
    int pri;
    // 写法需要记住
    bool operator<(msg x) const
    {
        return pri > x.pri;
    }
};

priority_queue<msg> Q1;
```
此时我们就完成来小顶堆的建立。
我一开始使用 `cin,cout` 来进行数据的输入输出，然后在第三个测试点（N很大）超时，于是换成 `scanf`和`printf` 解决超时。
完整代码如下：
```cpp
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct msg
{
    char content[12];
    int pri;
    // 写法需要记住
    bool operator<(msg x) const
    {
        return pri > x.pri;
    }
};

priority_queue<msg> Q1; // 默认输出是大顶堆，所以我们要

int main()
{
    int n;
    scanf("%d", &n);
    char type[5], name[12];
    int pri;
    msg node;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", type);
        if (strcmp(type, "PUT") == 0)
        {
            scanf("%s", &node.content);
            scanf("%d", &node.pri);
            Q1.push(node);
        }
        else
        {
            if (Q1.size() > 0)
            {
                msg top = Q1.top();
                Q1.pop();
                printf("%s\n", top.content);
            }
            else
            {
                printf("EMPTY QUEUE!\n");
            }
        }
    }
    return 0;
}
```