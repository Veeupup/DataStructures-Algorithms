#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    pair<string, int> p("haha", 5);
    cout << p.first << endl;

    int x = 1, y = 2;
    swap(x, y);
    printf("%d %d \n", x, y);
    
    int arr[10] = {1, 2};
    swap(arr[0], arr[1]);
    printf("%d %d \n", arr[0], arr[1]);

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    reverse(arr, arr+5);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    int a[10] = {1, 3, 3, 3, 5, 2, 6, 9, 8, 4};
    int *lowerPos = lower_bound(a, a+10, -1);
    int *upperPos = upper_bound(a, a +10, -1);
    printf("find -1 :%d %d\n", lowerPos - a, upperPos -a);

    lowerPos = lower_bound(a, a+10, 3);
    upperPos = upper_bound(a, a+10, 3);
    printf("find 3 :%d %d\n", lowerPos - a, upperPos -a);

    return 0;
}
