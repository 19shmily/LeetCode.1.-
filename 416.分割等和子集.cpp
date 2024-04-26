#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution_416_1 {
public:
    bool canPartition(vector<int>& nums) {
        int l = 1;
        int r = nums.size() - 2;
        vector<int>lnums(r + 2);
        vector<int>rnums(r + 2);
        lnums[0] = nums[0];
        rnums[0] = nums[r + 1];
        while (r >= 0)
        {
            lnums[l] += lnums[l - 1];
            rnums[l] += rnums[r + 1];
            l++; r--;
        }
        int m = nums.size();
        for (int n = 0; n < m; n++)
        {
            if (lnums[n] == rnums[n])
            {
                return true;
            }
        }
        return false;
    }
};

//动态规划，官方题解，自己没写出来，但是基本看懂了
//可以把这道题翻译成，找出数组所有数之和的一半
class Solution_416_2 {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();//储存数组大小
        if (n < 2) {
            return false;//个数小于2直接返回，因为总有一个空的
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);//把所有的累加求和
        int maxNum = *max_element(nums.begin(), nums.end());//找出数组里最大的数
        if (sum & 1) {
            return false;//如果和是奇数，那不可能分成两个相等的数，直接返回错
        }
        int target = sum / 2;//计算最大值的一半，也就是目标值
        if (maxNum > target) {
            return false;//如果最大的数大于和的一半，也一定是错的，直接返回
        }
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
//表示从数组的[0,i]下标范围内选取若干个正整数，是否存在一种选取方案使得被选取的正整数的和等于j
//也就是把所有的可以由数组里的数能组成的数全部枚举出来，然后看最后的那个数是否可以成功组成
//依次加入数组里的数，然后把从1到目标数之间的数，依次组合一遍
//用i来表示每次新加的数的下标，j表示1到目标数之间的数，也就是和的意思
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;//j代表和，0肯定所有的都可以
        }
        dp[0][nums[0]] = true;//第一个数，，还要求下标是（0，0），肯定直接用他本身就可以组成了
        for (int i = 1; i < n; i++) {//前面把边界都处理好了，开始dp
            int num = nums[i];//记录当前访问到的下标的数
            for (int j = 1; j <= target; j++) {//开始组合1到目标值之间的数
                if (j >= num) {//如果和大于每次新多的数，就表示一定是要组合的
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                    //dp[i - 1][j]表示在新加num之前是否可以组合出来
                    //dp[i - 1][j - num]表示在加上总和减去num的数，在之前是否可以组合出来
                }
                else {
                    dp[i][j] = dp[i - 1][j];//如果小的话，直接看之前是否可以组合出来，因为加上肯定会大于和
                }
            }
        }
        return dp[n - 1][target];
    }
};

