#include <stdio.h>
#include <string.h>

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// 或者参数名为 intArr[],但是最终还是会转换为 int *intArr 这样的指针
int max(int *intArr, int len)
{
    int i, maxValue = intArr[0];
    for (int i = 0; i < len; i++)
    {
        if (maxValue < intArr[i])
        {
            maxValue = intArr[i];
        }
    }
    return maxValue;
}

// 不要返回局部变量的指针,有的编译器会报错
// int *func() {
//     int n = 100;
//     return &n;
// }

char *strlong(char *str1, char *str2)
{
    if (strlen(str1) >= strlen(str2))
    {
        return str1;
    }
    else
    {
        return str2;
    }
}

//返回两个数中较大的一个
int maxNum(int a, int b){
    return a>b ? a : b;
}

int main()
{
    int ff = 100;
    char str[20] = "tanweime.com";
    printf("%#X, %p\n", &ff, str);

    int a = 15, b = 99, c = 222;
    int *p = &a; //定义指针变量
    *p = b;      //通过指针变量修改内存上的数据
    c = *p;      //通过指针变量获取内存上的数据
    printf("%d, %d, %d, %d\n", a, b, c, *p);

    int x1 = 11, y1 = 22;
    printf("x1 = %d , x2 = %d \n", x1, y1);
    swap(&x1, &y1);
    printf("x1 = %d , x2 = %d \n", x1, y1);

    int num[6] = {11, 22, 33, 44, 55};
    int len = sizeof(num) / sizeof(int);
    printf("max is : %d !\n", max(num, len));

    // 两种定义字符串的方式
    char str1[20] = {'H', 'e', 'l', 'l', 'o'};
    char *str2 = "helloworld";
    char *str3;
    str3 = strlong(str1, str2);
    printf("The longer is : %s \n", str3);

    // 使用局部变量的地址作为返回值
    // int *pp = func(), n;
    // n = *pp;
    // printf("value = %d \n", n);

    // 多级指针
    int twa = 100;
    int *p1 = &twa;
    int **p2 = &p1;
    int ***p3 = &p2;
    printf("%d, %d, %d, %d\n", twa, *p1, **p2, ***p3);
    printf("&p2 = %#X, p3 = %#X\n", &p2, p3);
    printf("&p1 = %#X, p2 = %#X, *p3 = %#X\n", &p1, p2, *p3);
    printf(" &twa = %#X, p1 = %#X, *p2 = %#X, **p3 = %#X\n", &twa, p1, *p2, **p3);

    char *strArr[3] = {
        "tanwei",
        "谭巍",
        "C Language"};
    printf("%s\n%s\n%s\n", strArr[0], strArr[1], strArr[2]);

    // 二维数组和指针
    int arr4[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int(*pArr4)[4];
    int i, j;
    pArr4 = arr4;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%2d  ", *(*(pArr4 + i) + j));
        printf("\n");
    }

    // 函数指针
    int (*pmax)(int, int) = maxNum, maxval;
    printf("x1 = %d , x2 = %d \n", x1, y1);
    maxval = (*pmax)(x1, y1);
    printf("maxval = %d \n", maxval);


    return 0;
}
