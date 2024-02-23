#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution_40 {
    vector<int>tmp;
    vector<vector<int>>ret;
    void my_find(vector<int>& candidates, int target, int index)
    {
        if (target == 0)
        {
            ret.push_back(tmp);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            if (i !=index && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            target -= candidates[i];
            if (target < 0) 
            { 
                return; 
            }
            tmp.push_back(candidates[i]);
            my_find(candidates, target, i + 1);
            tmp.pop_back();
            target += candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        my_find(candidates, target, 0);
        return ret;
    }
};
