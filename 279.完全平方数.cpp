#include<iostream>
#include<vector>
using namespace std;

//超时
class Solution_279_1 {
    int count = 0;
    int ret = INT_MAX;
    void work(int n)
    {
        if (!n) 
        { 
            ret = ret > count ? count : ret;
            return; 
        }
        count++;
        int tmp = 1;
        while (tmp * tmp <= n)
        {
            work(n - tmp * tmp);
            tmp++;
        }
        count--;
    }
public:
    int numSquares(int n) {
        work(n);
        return ret;
    }
};

//官方题解，只能说动态规划牛逼
class Solution_279_2 {
public:
    int numSquares(int n) {
        vector<int> f(n + 1);//声明一个n+1长的数组，为了可以访问到n
        for (int i = 1; i <= n; i++) {//从下标1，也就是数字1的组成开始枚举
            int minn = INT_MAX;//记录最小值
            for (int j = 1; j * j <= i; j++) {
                minn = min(minn, f[i - j * j]);//i-j*j的意思就是：取到了j*j，不断查询剩下部分的最小组成
            }
            f[i] = minn + 1;//剩余部分最小组成数加1，即当前数的最小组成
        }
        return f[n];
    }
};