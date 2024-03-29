#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//������̫��ª��
class Solution_560_1 {
    int ret;
public:
    int subarraySum(vector<int>& nums, int k) {
        ret = 0;
        int m = nums.size();
        for (int n = 0; n < m; n++)
        {
            int sum = 0;
            for (int i = n; i < m; i++)
            {
                sum += nums[i];
                if (sum == k) { ret++; }
            }
        }
        return ret;
    }
};

//��ϣ��������ÿ�δ�1��n�ļӺͣ�ֵ��ͳ�������
//ÿ�μ���nums[n]ͨ����Ѱ�Ƿ����sum-k���ж��Ƿ��к�Ϊk���Ӵ�
//��Ϊ�����������Ϊǰ׺����sum��ȥһ��ǰ׺��kʱ������ں�Ϊk���Ӵ�������Ϊsum-k�Ķ�Ӧ��ֵ
class Solution_560_2 {
    int ret;
public:
    int subarraySum(vector<int>& nums, int k) {
        ret = 0;
        int m = nums.size();
        unordered_map<int, int>mp;
        mp[0] = 1;
        int sum = 0;
        for (int n = 0; n < m; n++)
        {
            sum += nums[n];
            if (mp.find(k - sum) != mp.end()) { ret += mp[k - sum]; }
            mp[sum]++;
        }
        return ret;
    }
};
