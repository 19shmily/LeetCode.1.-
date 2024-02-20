#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//下一个排列
class Solution_31 {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) { cout << nums[0] << endl; }
        int flag = nums.size() - 1;
        int judg = 0;
        int tmp1,tmp2;
        int arr[100] = { 0 };
        for (vector<int>::iterator it = nums.end() - 1; it != nums.begin(); it--)
        {
            arr[*it] = flag;
            if ((*it) > (*(it - 1)))
            {
                for (int n = *(it - 1) + 1; n < 100; n++)
                {
                    if (arr[n] != 0)
                    {
                        tmp1 = n;
                        tmp2 = arr[n];
                        break;
                    }
                }
                judg = 1;
                nums[tmp2] = nums[flag - 1];
                nums[flag - 1] = tmp1;
                sort(it, nums.end());
                break;
            }
            
            flag--;
        }
        if (!judg)
        {
            sort(nums.begin(), nums.end());
        }
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        {
            cout << (*it) << " ";
        }
        cout << endl;
        return;
    }
};

//int main()
//{
//    vector<int>arr;
//    arr.push_back(1);
//    arr.push_back(1);
//    arr.push_back(5);
//    Solution_31 test;
//    test.nextPermutation(arr);
//
//    system("pause");
//    return 0;
//}