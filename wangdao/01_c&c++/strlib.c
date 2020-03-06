#include<stdio.h>
#include<stdint.h>
#include<string.h>

/* 
    由于 C 语言的字符串拷贝函数不是很好用，自己可以写一个简单的拷贝函数
    dst 为目标地址 src 为源字符串地址 n 为复制的长度
 */
char *copy(char *dst, char *src, int n) {
    char *p = src;
    char *q = dst;
    int len = strlen(src);
    if(n > len) n = len;
    while (n--)
    {
        *(q++) = *(p++);
    }
    *(q++)='\0';    // 在末尾添加上
    return dst;
}

/* 
    字符串截取函数，三个参数分别为
    src 源字符串地址, start 开始位置， length 截取长度
 */
char *strsub(char *src, int start, int length) {
    int len = strlen(src);
    src += start;
    char *p = src + start + length - 1;
    *p = '\0';
    return src;
}


int main()
{
    // freopen("data.txt","r", stdin);
    char dest[10];
    char src[10] = "abcdef";
    printf("src's length = %d\n", strlen(src));
    printf("dest's length = %d\n", strlen(dest));
    copy(dest, src+1, 3);
    printf("after copy, dest's length = %d\n", strlen(dest));
    printf("%s \n", dest);
    char *str = strsub(src, 1, 3);
    printf("after sub, src : %s, length = %d\n", str, strlen(str));


    /* 
        字符串查找可以使用 strstr 函数
     */
    char a[100] = "abcdefgh";
    char b[100] = "cd";
    char *p = strstr(a, b);
    printf("b is at a: %d\n", p-a+1);

    char *p1 = "abcdef";
    int N = 10;
    char *p2 = (char*)malloc(sizeof(char)*N);
    char *p3 = (char*)memcpy(p2, p1+1, 4);
    printf("p2 = %s\np3 = %s\n", p2, p3);
    printf("p2's length: %d\n", strlen(p2));
    return 0;
}