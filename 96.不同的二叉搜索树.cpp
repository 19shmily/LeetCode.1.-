#include<iostream>
#include<string>
#include<vector>
using namespace std;

//��������ֵ�Ƕ��٣�ֻҪ������ͬ�����Ҹ����������ɵĶ����������ĸ�����һ����
//���Զ�̬�滮
//��������ȷ�����ڵ����ĸ���
//�ڲ������ΰ�ʣ�µ����ŵ����ң�dp[m]����m����������ɵĶ����������ĸ���
//��������˵Ľ�������
class Solution_96 {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};