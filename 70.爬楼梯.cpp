#include<iostream>
#include<vector>
using namespace std;

//最经典的动态规划
//是第一个见的dp，但不是第一个写的dp
//看了题解，其实直接用三个数代替vector容器更省空间
class Solution_70 {
public:
    int climbStairs(int n) {
        if (n == 1) { return 1; }
        if (n == 2) { return 2; }
        vector<int>tmp;
        tmp.push_back(1);
        tmp.push_back(2);
        for (int i = 3; i <= n; i++)
        {
            tmp.push_back(tmp[0] + tmp[1]);
            tmp.erase(tmp.begin());
        }
        return tmp[1];
    }
};