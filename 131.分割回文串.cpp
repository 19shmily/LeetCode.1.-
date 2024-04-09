#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
    vector<string>tmp;
    vector<vector<string>>ret;
    bool judg(string chs)
    {
        int l = 0, r = chs.size() - 1;
        while (l < r)
        {
            if (chs[l] != chs[r]) { return false; }
            l++; r--;
        }
        return true;
    }
    bool deal()
    {
        int m = tmp.size();
        for (int n = 0; n < m; n++)
        { 
            if (!judg(tmp[n])) { return false; }
        }
        return true;
    }
    void work(int n, string s)
    {
        string chs;
        int m = s.size();
        if (n == m)
        {
            if (deal()) { ret.push_back(tmp); }
        }
        for (int i = n; i < m; i++)
        {
            chs.push_back(s[i]);
            tmp.push_back(chs);
            work(i + 1, s);
            tmp.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        work(0, s);
        return ret;
    }
};