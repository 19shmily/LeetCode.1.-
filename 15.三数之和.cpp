#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

//三数之和
 class Solution_15 {
 public:
	 vector<vector<int>> threeSum(vector<int>& nums) {
		 vector<vector<int>> ret;
		 sort(nums.begin(), nums.end());
		 int sum = 0;
		 int left = 0;
		 int right = 0;
		 int number = 0;
		 for (int i = 0; i < nums.size() - 2; i++)
		 {
			 if (i && nums[i] == nums[i - 1])
			 {
				 continue;
			 }
			 sum = 0 - nums[i];
			 left = i + 1;
			 right = nums.size() - 1;
			 while (left < right)
			 {

				 if ((nums[left] + nums[right]) < sum)
				 {
					 left++;
					 continue;
				 }
				 if ((nums[left] + nums[right]) > sum)
				 {
					 right--;
					 continue;
				 }
				 if ((nums[left] + nums[right]) == sum)
				 {
					 ret.push_back({ nums[i] ,nums[left],nums[right] });
					 left++;
					 right--;
					 while (left < right && nums[left] == nums[left - 1])
					 {
						 left++;
					 }
					 while (right > left && nums[right] == nums[right + 1])
					 {
						 right--;
					 }
					 continue;
				 }
			 }
		 }
		 return ret;
	 }
 };

 //三数之和的main函数
 //int main()
 //{
	// vector<int> test;
	// test.push_back(-1);
	// test.push_back(0);
	// test.push_back(1);
	// test.push_back(2);
	// test.push_back(-1);
	// test.push_back(-4);
	// Solution_15 temp;
 //    vector<vector<int>> recept = temp.threeSum(test);
	// int n = 0;
	// for (vector<vector<int>>::iterator it = recept.begin(); it < recept.end(); it++)
	// {
	//	 cout << recept[n][0] << " " << recept[n][1] << " " << recept[n][2] << endl;
	//	 n++;
	// }

	// system("pause");
	// return 0;
 //}