#include<iostream>
#include<vector>
using namespace std;

class Solution_80 {
    bool judg;
public:
    int removeDuplicates(vector<int>& nums) {
        judg = false;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i - 1])
            {
                if (judg)
                {
                    nums.erase(nums.begin() + i);
                    i--;
                }
                else
                {
                    judg = true;
                }
            }
            else
            {
                judg = false;
            }
        }
        return nums.size();
    }
};