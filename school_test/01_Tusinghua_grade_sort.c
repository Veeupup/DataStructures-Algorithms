/*
    Author: Veeupup
    成绩排序，使用
    * 冒泡排序
    * 选择排序
    * 插入排序
    * 归并排序
    * 堆排序
    * 快速排序

 */
#include<stdio.h>
#include<stdint.h>

struct Stu
{
    int id;
    int score;
}stu[100];

void bubbleSort(int n);
void selectSort(int n);
void insertSort(int n);

int main()
{
    freopen("data.txt","r", stdin);
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &stu[i].id, &stu[i].score);
        }
        // bubbleSort(n);
        // selectSort(n);
        insertSort(n);
        for (int i = 0; i < n; i++)
        {
            printf("%d %d\n", stu[i].id, stu[i].score);
        }
    }
    return 0;
}

void swap(int i, int j)
{
    int tempId = stu[i].id;
    int tempScore = stu[i].score;
    stu[i].id = stu[j].id;
    stu[i].score = stu[j].score;
    stu[j].id = tempId;
    stu[j].score = tempScore;
}

void bubbleSort(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(stu[i].score > stu[j].score)
                swap(i, j);
            else if(stu[i].score == stu[j].score && stu[i].id > stu[j].id) {
                // 如果分数相同，那么把大的学号放到后面来
                swap(i, j);
            }
        }
        
    }
};

void selectSort(int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if(stu[j].score < stu[min].score)
                min = j;
            else if(stu[j].score == stu[min].score && stu[j].id < stu[min].id)
                min = j;    // 如果分数相同，那么将 id 较小的放到前面
        }
        if(min != i)
            swap(i, min);
    }
}

void insertSort(int n)
{
    for (int i = 1; i < n; i++)
    {
        int getScore = stu[i].score;
        int getId = stu[i].id;  // 抓到的牌
        int j = i - 1;  // 假定左边的牌已经是有序的了
        while (j >= 0 && (stu[j].score > getScore || stu[j].score == getScore && stu[j].id > getId))
        {   // 抓到的牌如果比自己手里的牌大，就把手里的牌右移
            // 或者是二者分数相等，然后就比较 id
            stu[j+1].id = stu[j].id;
            stu[j+1].score = stu[j].score;
            j--;
        }
        stu[j+1].score = getScore;
        stu[j+1].id = getId;    // 直到该手牌比抓到的牌小，或者二者相等，将抓到的牌放到该牌的右边
    }
    
}


