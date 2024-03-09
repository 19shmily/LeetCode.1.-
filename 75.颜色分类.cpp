#include<iostream>
#include<vector>

using namespace std;

class Solution_75 {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        for (int n = 0; (n <= right && left != right); n++)
        {
            if (nums[n] == 0)
            {
                int tmp = nums[left];
                nums[left] = 0;
                nums[n] = tmp;
                left++;
                while (nums[left] == 0 && left < right)
                {
                    left++;
                }
                n = left - 1;
            }
            else if (nums[n] == 2)
            {
                int tmp = nums[right];
                nums[right] = 2;
                nums[n] = tmp;
                right--;
                n--;
                while (nums[right] == 2 && left < right)
                {
                    right--;
                }
            }
            else
            {
                continue;
            }
        }
        return;
    }
};

//int main()
//{
//    Solution_75 test;
//    vector<int>tmp;
//    tmp.push_back(2);
//    tmp.push_back(0);
//    tmp.push_back(2);
//    tmp.push_back(1);
//    tmp.push_back(1);
//    tmp.push_back(0);
//
//    test.sortColors(tmp);
//
//    return 0;
//}