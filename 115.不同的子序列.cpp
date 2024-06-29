#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution_115 {
    unordered_map<char, vector<unsigned long long>>mp;
public:
    int numDistinct(string s, string t) {
        int m = t.size();
        vector<unsigned long long>dp(m + 1);
        dp[0] = 1;
        for (int n = 0; n < m; n++)
        {
            mp[t[n]].push_back(n + 1);
        }
        m = s.size();
        for (int n = 0; n < m; n++)
        {
            if (mp.count(s[n]))
            {
                for (int i = mp[s[n]].size() - 1; i >= 0; i--)
                {
                    dp[mp[s[n]][i]] += dp[mp[s[n]][i] - 1];
                }
            }
        }
        return dp[t.size()];
    }
};

int main()
{
    string s = "rabbbit";
    string t = "rabbit";
    Solution_115 test;
    test.numDistinct(s, t);
    return 0;
}