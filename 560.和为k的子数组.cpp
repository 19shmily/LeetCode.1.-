#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//暴力，太丑陋了
class Solution_560_1 {
    int ret;
public:
    int subarraySum(vector<int>& nums, int k) {
        ret = 0;
        int m = nums.size();
        for (int n = 0; n < m; n++)
        {
            int sum = 0;
            for (int i = n; i < m; i++)
            {
                sum += nums[i];
                if (sum == k) { ret++; }
            }
        }
        return ret;
    }
};

//哈希表，索引是每次从1到n的加和，值是统计其个数
//每次加完nums[n]通过找寻是否存在sum-k来判断是否有和为k的子串
//因为索引可以理解为前缀，当sum减去一个前缀是k时，则存在和为k的子串，个数为sum-k的对应的值
class Solution_560_2 {
    int ret;
public:
    int subarraySum(vector<int>& nums, int k) {
        ret = 0;
        int m = nums.size();
        unordered_map<int, int>mp;
        mp[0] = 1;
        int sum = 0;
        for (int n = 0; n < m; n++)
        {
            sum += nums[n];
            if (mp.find(k - sum) != mp.end()) { ret += mp[k - sum]; }
            mp[sum]++;
        }
        return ret;
    }
};
