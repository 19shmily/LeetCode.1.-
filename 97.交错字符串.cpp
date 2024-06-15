#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution_97 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m1 = s1.size(), m2 = s2.size(), m3 = s3.size();
        vector<vector<int>>dp(m1 + 1, vector<int>(m2 + 1));
        dp[0][0] = 1;
        if (m1 + m2 != m3) { return false; }
        for (int n1 = 0; n1 <= m1; n1++) { 
            for (int n2 = 0; n2 <= m2; n2++) { 
                int p = n1 + n2 - 1;
                if (n1 > 0) {
                    dp[n1][n2] |= (dp[n1 - 1][n2] && s1[n1 - 1] == s3[p]);
                }
                if (n2 > 0) {
                    dp[n1][n2] |= (dp[n1][n2 - 1] && s2[n2 - 1] == s3[p]);
                }
            }
        }
        return dp[m1][m2];
    }
};

int main()
{
    Solution_97 test;
    test.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    return 0;
 }