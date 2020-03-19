#include <stdio.h>

/* 
    结构体学习
 */

struct stu
{
    char *name;
    int num;
    int age;
    char group;
    float score;
} stu3, class[5] = {
            {"Li ping", 5, 18, 'C', 145.0},
            {"Zhang ping", 4, 19, 'A', 130.5},
            {"He fang", 1, 18, 'A', 148.5},
            {"Cheng ling", 2, 17, 'F', 139.0},
            {"Wang ming", 3, 17, 'B', 144.5}};

// 使用 const 修饰,放置在函数内部修改指针指向的数据
void print_stu(const struct stu *ps) {
    printf("function test: %s, %d \n", ps->name, ps->age);
}

union data {
    int n;
    char ch;
    double f;
}unA, unB, unC;



int main()
{
    // 结构体定义
    struct stu stu1, stu2;
    stu1.name = "Tom";
    stu1.num = 12;
    stu1.age = 18;
    stu1.group = 'A';
    stu1.score = 136.5;
    //读取结构体成员的值
    printf("%s的学号是%d，年龄是%d，在%c组，今年的成绩是%.1f！\n", stu1.name, stu1.num, stu1.age, stu1.group, stu1.score);

    // 结构体数组
    int i, num_140 = 0;
    float sum = 0;
    for (i = 0; i < 5; i++)
    {
        sum += class[i].score;
        if (class[i].score < 140)
            num_140++;
    }
    printf("sum=%.2f\naverage=%.2f\nnum_140=%d\n", sum, sum / 5, num_140);

    // 定义结构体指针
    struct stu *pstu = &stu1;
    printf("pstu.name : %s\n", (*pstu).name);
    // -> 运算符可以直接使用 pstu 指针访问结构体内容供
    printf("pstu.name -> : %s\n", pstu->name);

    // 使用制表符打印输出
    int len = sizeof(class) / sizeof(struct stu);
    printf("Name\t\tNum\tAge\tGroup\tScore\t\n");
    struct stu *ps;
    for (ps = class; ps < class + len; ps++)
    {
        printf("%s\t%d\t%d\t%c\t%.1f\n", ps->name, ps->num, ps->age, ps->group, ps->score);
    }

    // 结构体作为函数参数
    print_stu(&stu1);

    // 枚举变量约束
    enum week { Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun} day;
    day = 1;
    switch (day)
    {
    case Mon:
        puts("Monday\n");
        break;
    case Tues:
        puts("Tuesday\n");
        break;
    case Wed:
        puts("Wednesday\n");
        break;
    case Thurs:
        puts("Thursday\n");
        break;
    case Fri:
        puts("Friday\n");
        break;
    default:
        break;
    }

    const int MAXN = 10;
    printf("%d\n", MAXN);

    const int *p1;  //  p1,p2 数据是只读的，但是指针本身指向的内容不能被改变
    int const *p2;  // 
    int * const p3; // 指针是只读的，指针本身不能被修改

    return 0;
}