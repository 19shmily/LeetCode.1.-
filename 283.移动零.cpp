#include<iostream>
#include<vector>

using namespace std;

class Solution_283 {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 2) { return; }
        int head = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0) {
                if (head < 0) { continue; }
                else {
                    nums[head] = nums[i];
                    head++;
                    nums[i] = 0;
                }
            }
            else if (head < 0)
            {
                head = i;
            }
        }
        return;
    }
};