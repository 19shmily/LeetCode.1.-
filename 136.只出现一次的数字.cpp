#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//自己写的用set容器
class Solution_136_1 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int>rem;
        int m = nums.size();
        for (int n = 0; n < m; n++)
        {
            auto it = rem.find(nums[n]);
            if (it == rem.end())
            {
                rem.insert(nums[n]);
            }
            else
            {
                rem.erase(it);
            }
        }
        return *rem.begin();
    }
};

//官方题解，位运算，因为a异或b两次还等于a
class Solution_136_2 {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto e : nums) ret ^= e;
        return ret;
    }
};
