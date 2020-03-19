/*
    Author: Veeupup
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string nums[4][10] = {
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"}
        };
        string roman;
        roman.append(nums[3][num / 1000]);
        roman.append(nums[2][num / 100 % 10]);
        roman.append(nums[1][num / 10 % 10]);
        roman.append(nums[0][num % 10]);
        return roman;
    }
};


int main()
{
    Solution *so = new Solution();
    int x1 = 1;
    



    return 0;

}