#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//
void search(vector<int>& nums,vector<int>& ret,int place, int target)
{
    int head = place, rear = place;
    int addnum = 1, subnum = 1;
    while (1)
    {
        head -= subnum;
        if (head < 0 || nums[head] != nums[place])
        {
            if (subnum == 1)
            {
                head += 1;
                break;
            }
            head += subnum;
            subnum = 1;
            continue;
        }
        subnum *= 2;
    }
    while (1)
    {
        rear += addnum;
        if (rear > nums.size() - 1 || nums[rear] != nums[place])
        {
            if (addnum == 1)
            {
                rear -= 1;
                break;
            }
            rear -= addnum;
            addnum = 1;
            continue;
        }
        addnum *= 2;
    }
        ret.push_back(head);
        ret.push_back(rear);
    return;
}
//�ҵ��������֮��
//���ϵ���ǰ�������������Ѱ�Ҳ����仯����±�
//��ȥǰһ�����ϵı���������ǰһ����ȥ�ı�����������������Ϊ1�����¼Ӽ�
//ֱ���Ӽ�1�ͻᷢ���仯��Խ��
class Solution_34_1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ret;
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                search(nums, ret, mid, target);
                return ret;
            }
        }
        ret.push_back(-1);
        ret.push_back(-1);
        return ret;
    }
};

//ͨ��Ѱ������ĵ�һ�������һ����
//��סÿ���ҵ����±�
//�ҵ�һ������������������
//�����һ������������������
//ֱ������������������
class Solution_34_2 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ret;
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        int head = -1, rear = -1;
        while (left <= right)
        {
            mid = left + ((right - left) >> 1);
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                head = mid;
                right = mid - 1;
            }
        }
        left = 0;
        right = nums.size() - 1;
        while (left <= right)
        {
            mid = left + ((right - left) >> 1);
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                rear = mid;
                left = mid + 1;
            }
        }
        ret.push_back(head);
        ret.push_back(rear);
        return ret;
    }
};

//int main()
//{
//    Solution_34 test;
//    vector<int>tmp;
//    tmp.push_back(2);
//    tmp.push_back(2);
//    vector<int> rec = test.searchRange(tmp, 2);
//    cout << rec[0] << " " << rec[1] << endl;
//    system("pause");
//    return 0;
//}