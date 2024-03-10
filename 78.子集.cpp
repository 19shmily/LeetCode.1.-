#include<iostream>
#include<vector>

using namespace std;

class Solution_78 {
    vector<vector<int>>ret;
    vector<int>tmp;
    void work(int n, vector<int>& nums)
    {
        for (int i = n; i < nums.size(); i++)
        {
            tmp.push_back(nums[i]);
            ret.push_back(tmp);
            work(i + 1, nums);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ret.push_back(tmp);
        work(0, nums);
        return ret;
    }
};