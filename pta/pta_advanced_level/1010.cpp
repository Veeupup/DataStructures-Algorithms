/*
    Author: Veeupup
    进制转换，二分法
    
    1.进制的区间范围 N2的下限通过找到其中最大的字符对应的数字Max加1即可。
    而N2的上限不能直接等于N1+1，因为若N1等于0，那么上限值就为1，最小的进制为2进制。
    所以要先判断Max是否大于N1的十进制值，若大于，则上限Max+1，反之则N1的十进制+1

    2. 输入的N1/N2转化成十进制后可能超过Int的范围，
    要用long long 由于是用他们转化成十进制后的数作为上限，
    因此进制的上限值以及进制的中间值都可能会超过Int的范围,所以都要用long long

    3. 转化时可能存在溢出情况 
    由于进制的上限会非常大，在转化时就有可能会溢出，溢出后结果<0，
    所以若转化成十进制后<0，上限要缩小


 */
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <string>
#include <cctype>
using namespace std;
typedef long long ll;

// 进制转换
ll convert(string n, ll r) {
    ll ans = 0;
    int index = 0, temp = 0;
    for (int i = 0; i < n.size(); i++)
    {
        temp = isdigit(n[i]) ? n[i] - '0' : n[i] - 'a' + 10;
        ans = ans * r + temp;
    }
    return ans;
}

// 找到令两个数相同的进制
ll find_r(string n, ll num) {
    ll low = 0, temp;
    for (int i = 0; i < n.size(); i++)
    {   // 这里加上 1 是因为如果 n1 为 0 的话，进制至少要从 2 开始
        temp = (isdigit(n[i]) ? n[i] - '0' : n[i] - 'a' + 10) + 1;
        if(temp > low)
            low = temp;
    }
    ll high = max(low, num);
    while (low <= high) 
    {
        ll mid = (low + high) / 2;
        ll t = convert(n, mid);
        if(t < 0 || t > num)
            high = mid - 1; // 进制找大了，小于零是因为有可能溢出了
        else if(t == num) return mid;
        else low = mid + 1;
    }
    return -1;
}

int main()
{
    freopen("data.txt","r", stdin);
    string n1, n2;
    ll tag = 0, r = 0, rr;
    cin >> n1 >> n2 >> tag >> r;
    rr = tag == 1 ? find_r(n2, convert(n1, r)) : find_r(n1, convert(n2, r));
    if(rr != -1)
        cout << rr;
    else 
        cout << "Impossible";
    return 0;

}