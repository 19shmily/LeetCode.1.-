#include<iostream>

using namespace std;

//自己写的类似快速减的思维
//但是还是比较慢的
class Solution_69_1 {
public:
    int mySqrt(int x) {
        int n = 1;
        long long tmp = x;
        while (1)
        {
            if (tmp * tmp <= x && (tmp + 1) * (tmp + 1) > x)
            {
                return tmp;
            }
            else if (tmp * tmp < x && (tmp + 1) * (tmp + 1) <= x)
            {
                tmp += n;
                n = 1;
                continue;
            }
            tmp -= n;
            if (tmp < 0) 
            {
                tmp += n;
                n = 1;
            }
            n *= 2;
        }
    }
};

//官方题解的二分查找
//其实自己写了二分，因为手误，没跑过，以为底层想法错了
//看了题解后，发现二分的想法其实没问题
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};