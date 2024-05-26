#include<iostream>
#include<vector>
using namespace std;

//ÒÑ³¬Ê±
class Solution_918_1 {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ret = INT_MIN;
        int m = nums.size();
        vector<int>tmp;
        for (int n = 0; n < m; n++)
        {
            int j = tmp.size();
            for (int i = 0; i < j; i++)
            {
                tmp[i] += nums[n];
                ret = tmp[i] > ret ? tmp[i] : ret;
            }
            tmp.push_back(nums[n]);
            ret = nums[n] > ret ? nums[n] : ret;
        }
        for (int n = 0; n < m; n++)
        {
            for (int i = n + 1; i < m; i++)
            {
                tmp[i] += nums[n];
                ret = tmp[i] > ret ? tmp[i] : ret;
            }
        }
        return ret;
    }
};


class Solution_918_2 {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ret = nums[0];
        int m = nums.size();
        vector<int> leftMax(m);
        leftMax[0] = nums[0];
        int tmp = nums[0];
        int sum = nums[0];
        for (int n = 1; n < m; n++)
        {
            sum += nums[n];
            tmp = tmp + nums[n] > nums[n] ? tmp + nums[n] : nums[n];
            ret = ret > tmp ? ret : tmp;
            leftMax[n] = max(leftMax[n - 1], sum);
        }
        sum = 0;
        for (int n = m - 1; n > 0; n--)
        {
            sum += nums[n];
            tmp = tmp + nums[n] > nums[n] ? tmp + nums[n] : nums[n];
            ret = max(ret, sum + leftMax[n - 1]);
        }
        return ret;
    }
};