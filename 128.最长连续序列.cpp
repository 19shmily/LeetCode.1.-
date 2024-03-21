#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

//自己的暴力排序，其实时间复杂度已经大于O(n)了
class Solution_128_1 {
    int count;
    int ret;
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        count = 0;
        ret = 0;
        for (int n = 0; n < nums.size(); n++)
        {
            if (count == 0)
            {
                count++;
            }
            else 
            {
                if (nums[n] == nums[n - 1]) { continue; }
                else if (nums[n] == nums[n - 1] + 1)
                {
                    count++;
                }
                else
                {
                    ret = ret > count ? ret : count;
                    count = 1;
                }
            }
        }
        return ret = count > ret ? count : ret;
    }
};

//官方的代码，先运用了无序set进行去重，再通过内置的count函数判断当前数的下一个数是否存在
//因为是无序的，所以存在就返回1，不存在就返回0
//因为每次进入count的循环都是从当前数开始数，还是时间复杂度很高
//通过count判断当前数减一是否存在，存在就跳过
//保证了每次进入循环都是从一个连续数的第一个数开始的
//从而把时间复杂度降到了O(2n)
class Solution_128_2 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
