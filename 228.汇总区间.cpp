#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution_228 {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        string s;
        vector<string>ret;
        nums.push_back(INT_MIN);
        int m = nums.size();
        int rem = nums[0];
        for (int n = 1; n < m; n++)
        {
            if ((long long)nums[n - 1] + 1 != nums[n])
            {
                s += to_string(rem);
                if (rem != nums[n - 1])
                {
                    s += "->";
                    s += to_string(nums[n - 1]);
                }
                ret.push_back(s);
                s.clear();
                rem = nums[n];
            }
        }
        return ret;
    }
};