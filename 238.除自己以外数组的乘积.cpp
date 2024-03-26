#include<iostream>
#include<vector>

using namespace std;

class Solution_238 {
    vector<int>ret;
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int m = nums.size();
        int tmp = 1;
        for (int n = 0; n < m; n++)
        {
            ret.push_back(tmp);
            tmp *= nums[n];
        }
        tmp = 1;
        for (int n = m - 1; n >= 0; n--)
        {
            ret[n] *= tmp;
            tmp *= nums[n];
        }
        return ret;
    }
};