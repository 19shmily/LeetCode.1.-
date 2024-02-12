#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//最接近的三数之和
class Solution_16 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left, right;
        int temp = 0;
        int ret;
        int sum = 0;
        int dif=INT_MAX;
        int flag = 1;
        vector<int>arr;
        for (int i = 0; i < nums.size(); i++)
        {
            left = i + 1;
            right = nums.size() - 1;
            while (right > left)
            {
                flag = 1;
                sum = nums[i] + nums[left] + nums[right];
                temp = target - sum;
                if (temp < 0)
                {
                    flag = -1;
                    temp = -temp;
                }
                if (dif > temp)
                {
                    ret = sum;
                    dif = temp;
                }
                if (dif == 0) { return ret; }
                if (temp * flag > 0)
                {
                    left++;
                    continue;
                }
                if (temp * flag < 0)
                {
                    right--;
                    continue;
                }
            }
        }
        return ret;
    }
};
//最接近的三数之和的main函数
//int main()
//{
//    vector<int> test;
//    test.push_back(-1);
//    test.push_back(2);
//    test.push_back(1);
//    test.push_back(-4);
//    //test.push_back(-1);
//    //test.push_back(-4);
//    Solution_16 temp;
//    int recept = temp.threeSumClosest(test, 1);
//    int n = 0;
//    cout << recept << endl;
//
//    system("pause");
//    return 0;
//}