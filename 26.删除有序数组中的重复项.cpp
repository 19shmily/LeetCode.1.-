#include<iostream>
#include<vector>

using namespace std;

//ɾ�����������е��ظ���
class Solution_26 {
public:
    int removeDuplicates(vector<int>& nums) {
        int flag = INT_MAX;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        {
            if (flag == *it)
            {
                nums.erase(it);
                it--;
            }
            else
            {
                flag = *it;
            }
        }
        return nums.size();
    }
};