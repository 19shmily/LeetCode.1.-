#include<iostream>
#include<vector>

using namespace std;

class Solution_55 {
	int max = 0;
	int insert = 0;
	void find_max(vector<int>&nums, int num1, int num2)
	{
		int n = num1 + 1;
		max = 0;
		insert = 0;
		while (n <= num2)
		{
			if (nums[n] + n - num1 > max)
			{
				max = nums[n] + n - num1;
				insert = n - num1;
			}
			n++;
		}
	}
public:
    bool canJump(vector<int>& nums) {
		int n = 0;
		while (1)
		{
			n += insert;
			if (n + nums[n] >= nums.size() - 1) { return true; }
			find_max(nums, n, n + nums[n]);
			if (max == 0) { return false; }
		}
    }
};

//int main()
//{
//	vector<int>arr;
//	arr.push_back(2);
//	arr.push_back(1);
//	arr.push_back(0);
//	arr.push_back(0);
//	Solution_55 test;
//	test.canJump(arr);
//
//	system("pause");
//	return 0;
//}