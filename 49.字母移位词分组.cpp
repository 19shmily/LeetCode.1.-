#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution_49 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for (int i = 0; i < strs.size(); i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            mp[key].emplace_back(strs[i]);
        }
        vector<vector<string>>ret;
        for (unordered_map<string, vector<string>>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            ret.emplace_back((*it).second);
        }
        return ret;
    }
};