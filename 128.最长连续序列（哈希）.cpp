#include<iostream>
#include<unordered_set>
using namespace std;

//自己又重写了一遍
class Solution_128_hash {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int m = nums.size();
        for (int n = 0; n < m; n++)
        {
            st.insert(nums[n]);
        }
        int ret = 0;
        for (int n = 0; n < m; n++)
        {
            int cnt = 1;
            int tmp = 1;
            while (st.count(nums[n] + tmp))
            {
                cnt++;
                st.erase(nums[n] + tmp);
                tmp++;
            }
            tmp = 1;
            while(st.count(nums[n] - tmp))
            {
                cnt++;
                st.erase(nums[n] - tmp);
                tmp++;
            }
            ret = ret > cnt ? ret : cnt;
        }
        return ret;
    }
};

int main()
{
    Solution_128_hash test;
    vector<int>nums;
    nums.push_back(100);
    nums.push_back(4);
    nums.push_back(200);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    test.longestConsecutive(nums);
    return 0;
}