#include<iostream>
#include<vector>

using namespace std;

class Solution_118 {
    vector<int>tmp;
    vector<vector<int>>ret;
public:
    vector<vector<int>> generate(int numRows) {
        for (int n = 0; n < numRows; n++)
        {
            tmp.clear();
            tmp.resize(n + 1, 1);
            for (int m = 1; m < n; m++)
            {
                tmp[m] = ret[n - 1][m - 1] + ret[n - 1][m];
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};

int main()
{
    Solution_118 test;
    test.generate(5);
    return 0;
}