#include<iostream>
#include<vector>
#include<string>
using namespace std;

//拿下拿下
class Solution_5_dp {
public:
    string longestPalindrome(string s) {
        int head = 0, rear = 0;
        int m = s.size();
        vector<vector<int>>dp(m, vector<int>(m, 0));//dp[i][j]记录从下标i到j是否为回文串
        for (int n = 0; n < m; n++) { dp[n][n] = 1; }
        for (int n = 1; n < m; n++)
        {
            for (int i = 0; i < n; i++)
            {
                if (s[n] == s[i])
                {
                    if (i == n - 1) 
                    { 
                        dp[i][n] = 1; 
                    }
                    else 
                    { 
                        dp[i][n] = dp[i + 1][n - 1]; 
                    }
                    if (n - i > rear - head && dp[i][n] == 1) { rear = n; head = i; }
                }
            }
        }
        string ret(s.begin() + head, s.begin() + rear + 1);
        return ret;
    }
};

int main()
{
    Solution_5_dp test;
    test.longestPalindrome("aacabdkacaa");
    return 0;
}