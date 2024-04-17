#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution_347 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> s;
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;

        for (auto t : mp)
            s.push_back({ t.second,t.first });

        sort(s.begin(), s.end());
        vector<int> res;
        int t = s.size() - 1;
        //不要用for(int i = s.size()-1;i>=s.size()-k;i--)
        //因为若s.size()= 1 , i= 0之后 i-1 正溢出
        while (k--) {
            res.push_back(s[t--].second);
        }
        return res;
    }
};
