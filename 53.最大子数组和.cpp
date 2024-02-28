#include<iostream>
#include<vector>

using namespace std;

class Solution_53 {
public:
    int maxSubArray(vector<int>& nums) {
        int tmp = nums[0];
        int ret = nums[0];
        for (int n = 1; n < nums.size(); n++)
        {
            if (tmp > 0)
            {
                tmp = tmp + nums[n];
            }
            else
            {
                tmp = nums[n];
            }
            ret = max(tmp, ret);
        }
        return ret;
    }
};