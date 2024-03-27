#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution_239 {
    multiset<int>tmp;
    vector<int>ret;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int m = nums.size() - k + 1;
        int n = 0;
        while (tmp.size() < k && n < m)
        {
            tmp.insert(nums[n]);
            n++;
        }
        ret.push_back(*(tmp.rbegin()));
        for (int i = n; i < m; i++)
        {
            auto it = tmp.find(nums[i - k]);
            tmp.erase(it);
            tmp.insert(nums[i]);
            ret.push_back(*(tmp.rbegin()));
        }
        return ret;
    }
};

//int main()
//{
//    Solution_239 test;
//    vector<int>nums;
//    nums.push_back(1);
//    nums.push_back(3);
//    nums.push_back(-1);
//    nums.push_back(-3);
//    nums.push_back(5);
//    nums.push_back(3);
//    nums.push_back(6);
//    nums.push_back(7);
//    test.maxSlidingWindow(nums,3);
//    return 0;
//}