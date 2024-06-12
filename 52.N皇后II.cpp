#include<iostream>
#include<vector>

using namespace std;

class Solution_52 {
    int ret;
    vector<int>rem;
    int length;
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
            ret++;
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
    int totalNQueens(int n) {
        length = n;
        mock(0);
        return ret;
    }
};