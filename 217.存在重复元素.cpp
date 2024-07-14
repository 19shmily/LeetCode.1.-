#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

//≈≈–Ú
class Solution_217_1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = nums.size();
        for (int n = 1; n < m; n++)
        {
            if (nums[n] == nums[n - 1]) { return true; }
        }
        return false;
    }
};

//π˛œ£±Ì
class Solution_217_2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        int m = nums.size();
        for (int n = 0; n < m; n++)
        {
            if (st.count(nums[n])) { return true; }
            st.insert(nums[n]);
        }
        return false;
    }
};