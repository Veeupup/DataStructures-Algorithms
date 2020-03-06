/* 
    “答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于 PAT 的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

    得到“答案正确”的条件是：

    * 字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
    * 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
    * 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
    
    现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

    输入格式：
    每个测试输入包含 1 个测试用例。第 1 行给出一个正整数 n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过 100，且不包含空格。

    输出格式：
    每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出 YES，否则输出 NO。

    输入样例：
        8
        PAT
        PAAT
        AAPATAA
        AAPAATAAAA
        xPATx
        PT
        Whatever
        APAAATAA

    输出样例：
        YES
        YES
        YES
        YES
        NO
        NO
        NO
        NO

    分析得答案正确的条件：
    * 1. 只含有且必须含有 P、A、T；
    * 2. P在T之前，两者数量为1，PT之间必有A;
    * 3. (P左侧A的数量) * (P、T之间A的数量) = T右侧A的数量;

 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define LEN 101

int main()
{
    freopen("data.txt", "r", stdin);
    int cnt_str = 0; // 字符串个数
    scanf("%d", &cnt_str);
    char str[LEN];
    int a, b, c;    // 统计前中后A的数量
    char *p;
    for (int i = 0; i < cnt_str; i++)
    {
        scanf("%s", str);
        a = b = c = 0;
        p = str;
        while (*p == 'A')
        {   // 统计P之前的A的字符数
            a++;
            p++;
        }
        if (*p == 'P')
        {   // 遇到 P 了
            p++;
            while (*p == 'A')
            {   // 统计 中间 A 的数量
                b++;
                p++;
            }
            if (*p == 'T')
            {   // 遇到 T 了
                p++;
                while (*p == 'A')
                {
                    c++;
                    p++;
                }
                // 这里的 !(*p) 是用来判断字符串是否已经达到了末尾
                if (!(*p) && b > 0 && a * b == c)
                {
                    printf("YES\n");
                    continue;
                }
            }
        }
        printf("NO\n");
    }
    return 0;
}