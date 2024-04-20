#include<iostream>
#include<vector>
using namespace std;

class Solution_198 {
public:
    int rob(vector<int>& nums) {
        int m = nums.size();
        int n_1 = 0, n_2 = 0;
        for (int n = 0; n < m; n++)
        {
            if (n_2 + nums[n] > n_1)
            {
                int tmp = n_2;
                n_2 = n_1;
                n_1 = tmp + nums[n];
            }
            else
            {
                n_2 = n_1;
            }
        }
        return n_1 > n_2 ? n_1 : n_2;
    }
};

int main()
{
    Solution_198 test;
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(1);

    test.rob(arr);
    return 0;
}