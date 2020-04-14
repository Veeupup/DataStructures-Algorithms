#include <iostream>
#include <vector>
#define LOCAL
using namespace std;

vector<int> arr1, arr2;

int main()
{ 
#ifdef LOCAL
    freopen("data.txt", "r", stdin);
#endif
    int n, num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        arr1.push_back(num);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        arr2.push_back(num);
    }
    vector<int> ans;
    int i = 0, j = 0, sum = 0, mid = (arr1.size() + arr2.size()) / 2;
    while (i < arr1.size() && j < arr2.size() && sum <= mid)
    {
        if(arr1[i] < arr2[j])  
            ans.push_back(arr1[i++]);
        else
            ans.push_back(arr2[j++]);
        sum++;
    }
    while (i < arr1.size() && sum <= mid)
    {
        ans.push_back(arr1[i++]);
        sum++;
    }
    while (j < arr2.size() && sum <= mid)
    {
        ans.push_back(arr2[j++]);
        sum++;
    }
    printf("%d", ans[mid-1]);
    return 0;
}