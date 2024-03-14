#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution_88 {
    vector<int>ret;
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) 
        {
            nums1 = nums2;
            return; 
        }
        else if (n == 0) { return; }
        int flag = 0;
        int i = 0;
        while (1)
        {
            if (flag == n + m - nums2.size())
            {
                copy(nums2.begin(), nums2.end(), nums1.begin() + flag);
                nums1.resize(n + m);
                return;
            }
            if (nums1[flag] == nums1[flag + 1])
            {
                flag++;
                continue;
            }
            if (nums1[flag] > nums2[0])
            {
                nums1.insert(nums1.begin() + i, nums2[0]);
                flag++;
                i++;
                nums2.erase(nums2.begin());
            }
            else if (nums2[0] <= nums1[flag + 1])
            {
                nums1.insert(nums1.begin() + flag + 1, nums2[0]);
                flag += 2;
                i = flag;
                nums2.erase(nums2.begin());
            }
            else
            {
                flag++;
            }
            if (nums2.size() == 0)
            {
                nums1.resize(n + m);
                return;
            }
        }
    }
};

//int main()
//{
//    Solution_88 test;
//    vector<int>nums1;
//    vector<int>nums2;
//    nums1.push_back(0);
//    nums1.push_back(3);
//    nums1.push_back(3);
//    nums1.push_back(0);
//    nums1.push_back(0);
//    nums1.push_back(0);
//    nums2.push_back(1);
//    nums2.push_back(2);
//    nums2.push_back(2);
//    test.merge(nums1, 3, nums2, 3);
//
//    return 0;
//}