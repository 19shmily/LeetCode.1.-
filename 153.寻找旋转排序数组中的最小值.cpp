#include<iostream>
#include<vector>

using namespace std;

class Solution_153 {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] >= nums[l] && nums[m] <= nums[r])
            {
                return nums[l];
            }
            else if (nums[l] <= nums[m])
            {
                l = m + 1;
            }
            else if (nums[r] >= nums[m])
            {
                if (nums[m] < nums[l])
                {
                    r = m;
                }
                else
                {
                    l = m;
                }
            }
        }
        return 0;
    }
};