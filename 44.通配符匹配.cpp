#include<iostream>
#include<string>
#include<vector>

using namespace std;

//超时，已寄
class Solution_44_1 {
    bool work(string s, string p, int n, int i)
    {
        bool flag = false;
        for (; n >= 0; n--)
        {
            if (flag)
            {
                if (i >= 0)
                {
                    if (p[i] == s[n] || p[i] == '?')
                    {
                        if (work(s, p, n - 1, i - 1)) { return true; }
                    }
                }
            }
            else
            {
                if (i < 0) { return false; }
                if (p[i] == s[n] || p[i] == '?')
                {
                    i--; continue;
                }
                if (p[i] == '*')
                {
                    n++;
                    flag = true;
                    do {
                        i--;
                    } while (i >= 0 && (p[i] == '*'));
                    continue;
                }
                return false;
            }
        }
        while (i >= 0 && (p[i] == '*'))
        {
            i--;
        }
        if (i != -1) { return false; }
        return true;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size() - 1;
        int i = p.size() - 1;
        return work(s, p, n, i);
    }
};

//只能说还是动态规划强
//如果递归会超时，那就动态规划！
class Solution_44_2 {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = true;
            }
            else {
                break;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    string s = "mississippi";
    string p = "m??*ss*?i*pi";
    Solution_44_1 test;
    test.isMatch(s, p);


    return 0;
}