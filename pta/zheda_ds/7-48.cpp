
#include <iostream>
#define LOCAL
using namespace std;

int main()
{ 
#ifdef LOCAL
    freopen("data.txt", "r", stdin);
#endif


    
    return 0;
}