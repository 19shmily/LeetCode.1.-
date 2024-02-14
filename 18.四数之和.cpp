#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//四数之和
class Solution_18 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if (nums.size() < 4)
        {
            return ret;
        }
        sort(nums.begin(), nums.end());
        if ((long long)nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3] + nums[nums.size() - 4] < target)
        {
            return ret;
        }
        for (int n = 0; n < nums.size() - 3; n++)
        {
            if (n && nums[n] == nums[n - 1])
            {
                continue;
            }
            if ((long long)nums[n] + nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3] < target)
            {
                continue;
            }
            int first = nums[n];
            for (int m = n + 1; m < nums.size() - 2; m++)
            {
                if (m != n + 1 && nums[m] == nums[m - 1])
                {
                    continue;
                }
                if ((long long)first + nums[m] + nums[nums.size() - 1] + nums[nums.size() - 2] < target)
                {
                    continue;
                }
                int second = nums[m];
                int left = m + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    if (left != m + 1 && nums[left] == nums[left - 1])
                    {
                        left++;
                        continue;
                    }
                    if (right != nums.size() - 1 && nums[right] == nums[right + 1])
                    {
                        right--;
                        continue;
                    }
                    long long sum = (long long)first + second + nums[left] + nums[right];
                    if (sum > target)
                    {
                        right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        ret.push_back({ first, second, nums[left], nums[right] });
                        right--;
                        left++;
                    }
                }
            }
        }
        return ret;
    }
};

//四数之和的main函数
//int main()
//{
//    vector<int> test;
//    test.push_back(0);
//    test.push_back(0);
//    test.push_back(0);
//    test.push_back(0);
//    //test.push_back(-2);
//    //test.push_back(2);
//    Solution_18 temp;
//    vector<vector<int>> recept = temp.fourSum(test,0);
//    int n = 0;
//    for (vector<vector<int>>::iterator it = recept.begin(); it < recept.end(); it++)
//    {
//        cout << recept[n][0] << " " << recept[n][1] << " " << recept[n][2] << " " << recept[n][3] << endl;
//   	 n++;
//    }
//
//    system("pause");
//    return 0;
//}