#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int m = nums.size();
        int ret = 0;
        sort(nums.begin(), nums.end());
        for (int n = 1; n < m; n++)
        {
            if (nums[n - 1] == nums[n])
            {
                return nums[n];
            }
        }
        return 0;
    }
};