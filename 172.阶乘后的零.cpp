#include<iostream>
#include<vector>

using namespace std;

//自己写的，双击败都才仅仅是5%
class Solution_172_1 {
public:
    int trailingZeroes(int n) {
        if (!n) { return 0; }
        int num = 1;
        int ret = 0;
        for (int i = 2; i <= n; i++)
        {
            num *= i;
            while (!(num % 10))
            {
                ret++;
                num /= 10;
            }
            num %= 100000;
        }
        return ret;
    }
};

//数学大法:只有2*5才可以得到一个0，那我们只需要看n！可以分解为多少个2*5就可以
//但是由于质因子5的个数不会大于质因子2的个数
//所以可以仅考虑质因子5的个数。
class Solution_172_2 {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};