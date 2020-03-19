#include<stdio.h>
#include<stdint.h>


int main()
{
    // 读取文件
    freopen("data.txt","r", stdin);
    int n;
    scanf("%d", &n);
    printf("read from data.txt : %d \n", n);

    // 写入文件
    freopen("file.txt","w+", stdout);
    printf("文本重定向到file.txt \n");


    return 0;
}