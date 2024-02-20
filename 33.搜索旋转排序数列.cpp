#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//ËÑË÷Ðý×ªÅÅÐòÊýÁÐ
class Solution_33 {
public:
    int search(vector<int>& nums, int target) {
        int right = nums.size() - 1;
        int left = 0;
        int mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) { return mid; }
            if (nums[mid] < nums[right])
            {
                if (target < nums[mid]||target>nums[right])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (target<nums[left] || target>nums[mid])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

//int main()
//{
//    Solution_33 test;
//    vector<int>tmp;
//    tmp.push_back(4);
//    tmp.push_back(5);
//    tmp.push_back(6);
//    tmp.push_back(0);
//    tmp.push_back(1);
//    tmp.push_back(2);
//    tmp.push_back(3);
//    int rec=test.search(tmp, 6);
//    cout << rec << endl;
//    system("pause");
//    return 0;
//}