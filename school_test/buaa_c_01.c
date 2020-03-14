#include <stdio.h>

/* 
    计算和以及平均数
 */
void test1()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int sum = a + b + c;
    double mean = sum / 3.0;
    printf("%d %.2f\n", sum, mean);
}

/* 
    反序输出
 */
void test2()
{
    int arr[4], pos = 0;
    int n;
    scanf("%d", &n);
    while (n != 0)
    {
        arr[pos++] = n % 10;
        n /= 10;
    }
    if(pos != 3) {
        printf("-1\n");
    }else {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum = sum * 10 + arr[i];
            // printf("%d", arr[i]);
        }
        printf("%d\n", sum);
    }
}

/* 
    输出前驱 后驱字符
 */
void test3()
{
    char c;
    scanf("%c", &c);
    printf("%c %c %c\n", c-1, c, c+1);
    printf("%d %d %d\n", c-1, c, c+1);
}

/* 
    四舍五入
 */
void test4()
{
    float x;
    int num;
    scanf("%f", &x);
    num = x + 0.5;
    printf("%d\n", num);
}

/* 
    计算空格和回车的个数
 */
void test5()
{
    int space = 0, enter = 0;
    char c;
    while ((c = getchar()) != EOF)
    {
        if(c == ' ')
            space++;
        else if(c == '\n')
            enter++;
    }
    printf("%d %d\n", space, enter);
}

/* 
    有三个 short 类型的变量 x, y
    把 x 的高 8 位作为 z 的高 8 位
    把 y 的高 8 位作为 z 的低 8 位
    输出 z 的值
 */
void test6()
{
    unsigned short x = 840, y = 2177, z = 0;
    x = x >> 8;
    y = y >> 8; // 只要高 8 位
    x = x << 8;
    z = x + y;
    printf("%hu", z);
}

int main()
{
    // freopen("data.txt", "r", stdin);
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    test6();
    return 0;
}