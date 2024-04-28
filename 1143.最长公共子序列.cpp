#include<iostream>
#include<string>
#include<vector>
using namespace std;

//���Լ���ͷ��β�Լ���dp��ʽ��Ȼ����ֽ��ģ�⣬д���ֱ��һ�ι�
//̫�гɾ͸���
//�ٲ�һ�䣺��̬�滮yyds
class Solution_1143 {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int i = text1.size();
        int j = text2.size();
        vector<vector<int>>dp(i, vector<int>(j, 0));
        for (int n = 0; n < i; n++)
        {
            for (int m = 0; m < j; m++)
            {
                if (text1[n] == text2[m])
                {
                    dp[n][m] = 1;
                    if (m > 0 && n > 0)
                    {
                        dp[n][m] += dp[n - 1][m - 1];
                    }
                }
                else
                {
                    if (!m && !n) { dp[n][m] = 0; }
                    else if (m == 0)
                    {
                        dp[n][m] = dp[n - 1][m];
                    }
                    else if (n == 0)
                    {
                        dp[n][m] = dp[n][m - 1];
                    }
                    else
                    {
                        dp[n][m] = max(dp[n - 1][m], dp[n][m - 1]);
                    }
                }
            }
        }
        return dp[i - 1][j - 1];
    }
};