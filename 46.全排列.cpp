#include<iostream>
#include<vector>

using namespace std;

class Solution_46 {
private:
    vector<vector<int>>ret;
    vector<int>tmp;
    vector<int>hmap;
    int flag = 0;
    void find(vector<int>& nums)
    {
        if (flag == nums.size())
        {
            ret.push_back(tmp);
            return;
        }
        for (int n = 0; n < nums.size(); n++)
        {
            if (hmap[n] == 0)
            {
                tmp.push_back(nums[n]);
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
    vector<vector<int>> permute(vector<int>& nums) {
        hmap.resize(nums.size(), 0);
        find(nums);
        return ret;
    }
};