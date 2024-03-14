#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution_90 {
    vector<vector<int>>ret;
    vector<int>tmp;
    void work(int n, vector<int>& nums)
    {
        for (int i = n; i < nums.size(); i++)
        {
            if (i > n && nums[i] == nums[i - 1]) { continue; }
            tmp.push_back(nums[i]);
            ret.push_back(tmp);
            work(i + 1, nums);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ret.push_back(tmp);
        work(0, nums);
        return ret;
    }
};

//int main()
//{
//    vector<int>arr;
//    arr.push_back(1);
//    arr.push_back(2);
//    arr.push_back(2);
//    arr.push_back(3);
//    Solution_90 test;
//    test.subsetsWithDup(arr);
//    return 0;
//}