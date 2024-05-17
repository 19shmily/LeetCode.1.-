#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution_219 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int m = nums.size();
        for (int n = 0; n < m; n++)
        {
            if (mp.count(nums[n]))
            {
                if (n - mp[nums[n]] <= k) { return true; }
                else
                {
                    mp[nums[n]] = n;
                }
            }
            else
            {
                mp.insert({ nums[n],n });
            }
        }
        return false;
    }
};