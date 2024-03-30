#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution_189 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = k % nums.size();
        if (n > (nums.size() / 2))
        {
            n = nums.size() - n;
            int tmp = nums.size();
            nums.resize(nums.size() + n);
            copy(nums.begin(), nums.begin() + n, nums.begin() + tmp);
            nums.erase(nums.begin(), nums.begin() + n);
            return;
        }
        for (int m = 0; m < n; m++)
        {
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
        }
        return;
    }
};

//int main()
//{
//    Solution_189 test;
//    vector<int>nums;
//    nums.push_back(1);
//    nums.push_back(2);
//    nums.push_back(3);
//    nums.push_back(4);
//    nums.push_back(5);
//    nums.push_back(6);
//
//    test.rotate(nums, 11);
//    return 0;
//}