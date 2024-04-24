#include<iostream>
#include<vector>

using namespace std;

class Solution_300 {
    int ret = 0;
public:
    int lengthOfLIS(vector<int>& nums) {
        int m = nums.size();
        if (m == 1) { return 1; }
        vector<int>dp(m);
        dp[0] = 1;
        for (int n = 1; n < m; n++)
        {
            int tmp = 1;
            for (int i = 0; i < n; i++)
            {
                if (nums[n] > nums[i])
                {
                    tmp = max(tmp, dp[i] + 1);
                }
            }
            ret = max(tmp, ret);
            dp[n] = tmp;
        }
        return ret;
    }
};

//int main()
//{
//    Solution_300 test;
//    vector<int>nums;
//    nums.push_back(1);
//    nums.push_back(3);
//    nums.push_back(6);
//    nums.push_back(7);
//    nums.push_back(9);
//    nums.push_back(4);
//    nums.push_back(10);
//    nums.push_back(5);
//    nums.push_back(6);
//    test.lengthOfLIS(nums);
//    return 0;
//}