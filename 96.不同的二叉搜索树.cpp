#include<iostream>
#include<string>
#include<vector>
using namespace std;

//不管数的值是多少，只要互不相同，并且个数相等则组成的二叉搜索树的个数是一定的
//所以动态规划
//外层遍历是确定根节点是哪个数
//内层是依次把剩下的数放到左右，dp[m]中是m个数可以组成的二叉搜索树的个数
//故左右相乘的结果再相加
class Solution_96 {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};