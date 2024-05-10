#include<iostream>
#include<vector>

using namespace std;

class Solution_209 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int m = nums.size();
        int sum = 0;
        int cnt = INT_MAX;
        for (int n = 0; n < m; n++)
        {
            sum += nums[n];
            if (sum >= target)
            {
                while (sum >= target)
                {
                    sum -= nums[l];
                    l++;
                }
                cnt = cnt > n - l + 2 ? n - l + 2 : cnt;
            }
        }
        return cnt == INT_MAX ? 0 : cnt;
    }
};