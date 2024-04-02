#include<iostream>
#include<vector>

using namespace std;

//看完题解后写的
//只能说自己菜还要多练
class Solution_41 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int m = nums.size();
        for (int n = 0; n < m; n++)
        {
            if (nums[n] <= 0) { nums[n] = m + 1; }
        }
        for (int n = 0; n < m; n++)
        {
            if (nums[n] < 0)
            { 
                int tmp = 0 - nums[n];
                if (tmp <= m) { nums[tmp - 1] = nums[tmp - 1] > 0 ? 0 - nums[tmp - 1] : nums[tmp - 1]; }
                continue; 
            }
            if (nums[n] <= m) { nums[nums[n] - 1] = nums[nums[n] - 1] > 0 ? 0 - nums[nums[n] - 1] : nums[nums[n] - 1]; }
        }
        for (int n = 0; n < m; n++)
        {
            if (nums[n] > 0) { return n + 1; }
        }
        return m + 1;
    }
};

//int main()
//{
//    Solution_41 test;
//    vector<int>tmp;
//    tmp.push_back(3);
//    tmp.push_back(4);
//    tmp.push_back(-1);
//    tmp.push_back(1);
//    test.firstMissingPositive(tmp);
//    return 0;
//}