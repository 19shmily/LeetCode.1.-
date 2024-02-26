#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution_47 {
private:
    vector<vector<int>>ret;
    vector<int>tmp;
    vector<int>hmap;
    int flag = 0;
    void find(vector<int>& nums)
    {
        int judg = -11;
        if (flag == nums.size())
        {
            ret.push_back(tmp);
            return;
        }
        for (int n = 0; n < nums.size(); n++)
        {
            if (hmap[n] == 0)
            {
                if (nums[n] == judg) { continue; }
                tmp.push_back(nums[n]);
                judg = nums[n];
                flag++;
                hmap[n]++;
                find(nums);
                tmp.pop_back();
                flag--;
                hmap[n]--;
            }
        }
        return;

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        hmap.resize(nums.size(), 0);
        find(nums);
        return ret;
    }
};