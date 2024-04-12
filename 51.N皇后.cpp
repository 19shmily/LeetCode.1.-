#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution_51 {
    vector<vector<string>>ret;
    vector<string>tmp;
    string s;
    vector<int>rem;
    int length;
    void padding(int m)
    {
        for (int n = 0; n < m; n++)
        {
            s.push_back('.');
        }
        return;
    }
    void build()
    {
        for (int i = 0; i < length; i++)
        {
            padding(rem[i]);
            s.push_back('Q');
            padding(length - rem[i] - 1);
            tmp.push_back(s);
            s.clear();
        }
        ret.push_back(tmp);
        tmp.clear();
    }
    bool judg()
    {
        int n = rem.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (rem[i] == rem[j]) { return false; }
                if (rem[i] - i + j == rem[j] || rem[i] + i - j == rem[j]) { return false; }
            }
        }
        return true;
    }
    void mock(int m)
    {
        if (m == length)
        {
            build();
            return;
        }
        for (int i = 0; i < length; i++)
        {
            rem.push_back(i);
            if (judg())
            {
                mock(m + 1);
            }
            rem.pop_back();
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        length = n;
        mock(0);
        return ret;
    }
};

int main()
{
    Solution_51 test;
    test.solveNQueens(4);
    return 0;
}