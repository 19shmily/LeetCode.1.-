#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int flag = 0;
        int ret = 0;
        int m = s.size();
        if (m < 2) { return 0; }
        if (s[0] == '(') { flag++; }
        vector<int>dp(m + 1);
        for (int n = 1; n < m; n++)
        {
            if (s[n] == '(')
            {
                flag++;
                dp[n] = 0;
            }
            else if (flag == 0)
            {
                dp[n] = 0;
            }
            else
            {
                flag--;
                dp[n] = dp[n - 1] + 2;
                if (n - dp[n] >= 0)
                {
                    dp[n] += dp[n - dp[n]];
                }
                ret = ret > dp[n] ? ret : dp[n];
            }
        }
        return ret;
    }
};