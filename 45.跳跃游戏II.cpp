#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution_45 {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) { return 0; }
        int maxpos = 0, fre = 0, right = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (i > right)
            {
                right = maxpos;
                fre++;
                if (right >= nums.size() - 1) { return fre + 1; }
            }
            maxpos = max(i + nums[i], maxpos);
        }
        return 1;
    }
};

//int main()
//{
//	vector<int>arr;
//	arr.push_back(2);
//	arr.push_back(3);
//	arr.push_back(1);
//    arr.push_back(1);
//	arr.push_back(4);
//	Solution_45 test;
//	test.jump(arr);
//
//	system("pause");
//	return 0;
//}