#include<iostream>
#include<vector>

using namespace std;

class Solution_162 {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r--;
            }
        }
        return r;
    }
};