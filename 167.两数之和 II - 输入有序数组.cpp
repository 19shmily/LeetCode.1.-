#include<iostream>
#include<vector>

using namespace std;

class Solution_167 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        vector<int>ret;
        while (l < r)
        {
            if (numbers[l] + numbers[r] < target)
            {
                l++;
            }
            else if (numbers[l] + numbers[r] > target)
            {
                r--;
            }
            else
            {
                ret.push_back(l + 1);
                ret.push_back(r + 1);
                return ret;
            }
        }
        return ret;
    }
};