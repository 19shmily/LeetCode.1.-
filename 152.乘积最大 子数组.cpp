#include<iostream>
#include<vector>
using namespace std;

//±©Á¦£¬³¬Ê±
class Solution_152_1 {
    int ret=INT_MIN;
public:
    int maxProduct(vector<int>& nums) {
        int m = nums.size();
        for (int n = 0; n < m; n++)
        {
            int tmp = nums[n];
            ret = max(ret, tmp);
            for (int i = n - 1; i >= 0; i--)
            {
                tmp *= nums[i];
                ret = max(ret, tmp);
            }
        }
        return ret;
    }
};

//dp
class Solution_152_2 {
    int ret = INT_MIN;
public:
    int maxProduct(vector<int>& nums) {
        int m = nums.size();
        vector<int>minn(m + 1, 1);
        vector<int>maxn(m + 1, 1);
        for (int n = 0; n < m; n++)
        {
            int tmp_min = min(nums[n], min(nums[n] * minn[n], nums[n] * maxn[n]));
            int tmp_max = max(nums[n], max(nums[n] * minn[n], nums[n] * maxn[n]));
            ret = ret > tmp_max ? ret : tmp_max;
            minn[n + 1] = tmp_min;
            maxn[n + 1] = tmp_max;
        }
        return ret;
    }
};

int main()
{
    Solution_152_2 test;
    vector<int>nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(-2);
    nums.push_back(4);
    test.maxProduct(nums);
    return 0;
}