#include<iostream>
#include<vector>
#include<string>
using namespace std;

//超时
//在最长回文串的dp基础上，再回溯，还是超时了
class Solution_132_1 {
    int ret = INT_MAX;
    void work(vector<vector<int>>& dp, int x,int sum)
    {
        int m = dp[0].size();
        if (x == m) { ret = ret > sum - 1 ? sum - 1 : ret; return; }
        for (int n = x; n < m; n++)
        {
            if (dp[x][n])
            {
                work(dp, n + 1, sum + 1);
            }
        }
    }
public:
    int minCut(string s) {
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
                }
            }
        }
        work(dp, 0, 0);
        return ret;
    }
};

//官解
class Solution_132_2 {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> g(n, vector<int>(n, true));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = (s[i] == s[j]) && g[i + 1][j - 1];
            }
        }

        vector<int> f(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            if (g[0][i]) {
                f[i] = 0;
            }
            else {
                for (int j = 0; j < i; ++j) {
                    if (g[j + 1][i]) {
                        f[i] = min(f[i], f[j] + 1);
                    }
                }
            }
        }

        return f[n - 1];
    }
};

//int main()
//{
//    Solution_132_1 test;
//    string s = "aab";
//    test.minCut(s);
//
//    return 0;
//}