#include <stdio.h>
#include <ctype.h>
#include <string.h>

void strlower(char *a)
{
    for (int i = 0; a[i]; i++)
    {
        if(isupper(a[i]))
            a[i] = tolower(a[i]);
    }
}

int main()
{
    // freopen("/Users/tanwei/workplace/algorithms/DataStructures-Algorithms/luogu/P1308 统计单词数/in", "r", stdin);
    char des[1000001], source[11], *q, *p; // p搜索到什么位置了， q最后一次找到单词的指针
    int flag = 0, ans = 0, ans1 = -1;
    gets(source);
    gets(des);
    strlower(source);
    strlower(des);
    int len = strlen(source);
    p = des;    // 设置为全部
    for (;q = strstr(p, source);)
    {   // 找到 && 前一个为空格 && 后一个为空格
        if(q != NULL && (q == des || *(q-1) == ' ') && (*(q + len) == '\0' || *(q+len) == ' '))
        {
            ans++;
            if(ans == 1)
                ans1 = q - des;
        }
        p = q + len;
    }
    if(ans > 0)
        printf("%d %d", ans, ans1);
    else
        printf("%d", ans1);
    return 0;
}