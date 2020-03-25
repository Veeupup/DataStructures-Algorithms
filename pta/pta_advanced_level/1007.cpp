/* 
    思路：
    sum为要求的最大和，temp为临时最大和，
    leftindex和rightindex为所求的子序列的下标，
    tempindex标记left的临时下标
    temp = temp + v[i]，
        当temp比sum大，就更新sum的值、leftindex和rightindex的值；
        当temp < 0，那么后面不管来什么值，都应该舍弃temp < 0前面的内容，
        因为负数对于总和只可能拉低总和，不可能增加总和，还不如舍弃～
    舍弃后，直接令temp = 0，并且同时更新left的临时值tempindex。
    因为对于所有的值都为负数的情况要输出0，第一个值，最后一个值，
    所以在输入的时候用flag判断是不是所有的数字都是小于0的，
    如果是，要在输入的时候特殊处理～
        

 */
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int n;
int main()
{
    cin >> n;
    vector<int> vec(n);
    int temp = 0, left = 0, right = n - 1, sum = -1;
    int tempidx = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
        temp += vec[i];
        if (temp < 0)
        {   // 如果当前和小于 0 那么就舍弃，并且继续走
            temp = 0;
            tempidx = i + 1;    // 左边的位置默认为下一个，舍弃当前这个
        }
        else if (temp > sum)
        {
            sum = temp; // 更新最大值
            right = i;  // 更新最右边的值
            left = tempidx;
        }
    }
    if (sum < 0)
        sum = 0;

    cout << sum << " " << vec[left] << " " << vec[right] << endl;
}