#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution_416_1 {
public:
    bool canPartition(vector<int>& nums) {
        int l = 1;
        int r = nums.size() - 2;
        vector<int>lnums(r + 2);
        vector<int>rnums(r + 2);
        lnums[0] = nums[0];
        rnums[0] = nums[r + 1];
        while (r >= 0)
        {
            lnums[l] += lnums[l - 1];
            rnums[l] += rnums[r + 1];
            l++; r--;
        }
        int m = nums.size();
        for (int n = 0; n < m; n++)
        {
            if (lnums[n] == rnums[n])
            {
                return true;
            }
        }
        return false;
    }
};

//��̬�滮���ٷ���⣬�Լ�ûд���������ǻ���������
//���԰�����ⷭ��ɣ��ҳ�����������֮�͵�һ��
class Solution_416_2 {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();//���������С
        if (n < 2) {
            return false;//����С��2ֱ�ӷ��أ���Ϊ����һ���յ�
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);//�����е��ۼ����
        int maxNum = *max_element(nums.begin(), nums.end());//�ҳ�������������
        if (sum & 1) {
            return false;//��������������ǲ����ֳܷ�������ȵ�����ֱ�ӷ��ش�
        }
        int target = sum / 2;//�������ֵ��һ�룬Ҳ����Ŀ��ֵ
        if (maxNum > target) {
            return false;//������������ں͵�һ�룬Ҳһ���Ǵ�ģ�ֱ�ӷ���
        }
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
//��ʾ�������[0,i]�±귶Χ��ѡȡ���ɸ����������Ƿ����һ��ѡȡ����ʹ�ñ�ѡȡ���������ĺ͵���j
//Ҳ���ǰ����еĿ������������������ɵ���ȫ��ö�ٳ�����Ȼ�������Ǹ����Ƿ���Գɹ����
//���μ��������������Ȼ��Ѵ�1��Ŀ����֮��������������һ��
//��i����ʾÿ���¼ӵ������±꣬j��ʾ1��Ŀ����֮�������Ҳ���Ǻ͵���˼
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;//j����ͣ�0�϶����еĶ�����
        }
        dp[0][nums[0]] = true;//��һ����������Ҫ���±��ǣ�0��0�����϶�ֱ����������Ϳ��������
        for (int i = 1; i < n; i++) {//ǰ��ѱ߽綼������ˣ���ʼdp
            int num = nums[i];//��¼��ǰ���ʵ����±����
            for (int j = 1; j <= target; j++) {//��ʼ���1��Ŀ��ֵ֮�����
                if (j >= num) {//����ʹ���ÿ���¶�������ͱ�ʾһ����Ҫ��ϵ�
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                    //dp[i - 1][j]��ʾ���¼�num֮ǰ�Ƿ������ϳ���
                    //dp[i - 1][j - num]��ʾ�ڼ����ܺͼ�ȥnum��������֮ǰ�Ƿ������ϳ���
                }
                else {
                    dp[i][j] = dp[i - 1][j];//���С�Ļ���ֱ�ӿ�֮ǰ�Ƿ������ϳ�������Ϊ���Ͽ϶�����ں�
                }
            }
        }
        return dp[n - 1][target];
    }
};

