#include <iostream>
#include <vector>
#define LOCAL
using namespace std;

vector<int> vec1, vec2;

int main()
{
#ifdef LOCAL
    freopen("data.txt", "r", stdin);
#endif
    int num;
    while (scanf("%d", &num) != EOF)
    {
        if (num == -1)
            break;
        vec1.push_back(num);
    }
    while (scanf("%d", &num) != EOF)
    {
        if (num == -1)
            break;
        vec2.push_back(num);
    }
    vector<int> ans;
    int i = 0, j = 0;
    while (i < vec1.size() && j < vec2.size())
    {
        if (vec1[i] < vec2[j])
            ans.push_back(vec1[i++]);
        else
            ans.push_back(vec2[j++]);
    }
    while (i < vec1.size())
        ans.push_back(vec1[i++]);
    while (j < vec2.size())
        ans.push_back(vec2[j++]);
    if (ans.size() > 0)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            if (i > 0)
                printf(" %d", ans[i]);
            else
                printf("%d", ans[i]);
        }
    }else
    {
        printf("NULL");
    }

    return 0;
}