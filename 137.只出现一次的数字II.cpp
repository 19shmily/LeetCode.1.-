#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

//�Լ�д��
class Solution_137_1 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        int m = nums.size();
        for (int n = 0; n < m; n++)
        {
            mp[nums[n]]++;
            if (mp[nums[n]] == 3) { mp.erase(nums[n]); }
        }
        return mp.begin()->first;
    }
};

//�ٽ�̾Ϊ��ֹ
//���ߣ����۹ٷ����
//���ӣ�https ://leetcode.cn/problems/single-number-ii/solutions/746993/zhi-chu-xian-yi-ci-de-shu-zi-ii-by-leetc-23t6/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

//����ȷ��ÿһ��������λ
class Solution_137_2 {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int total = 0;
            for (int num : nums) {
                total += ((num >> i) & 1);
            }
            if (total % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};

//���ֵ�·���
class Solution_137_3 {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int num : nums) {
            tie(a, b) = pair<int, int>{ (~a & b & num) | (a & ~b & ~num), ~a & (b ^ num) };
        }
        return b;
    }
};

//���ֵ�·����Ż�
class Solution_137_4 {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int num : nums) {
            b = ~a & (b ^ num);
            a = ~b & (a ^ num);
        }
        return b;
    }
};