#include<iostream>
#include<vector>

using namespace std;

class Solution_119_1 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ret(1, 1);
        if (rowIndex == 0) { return ret; }
        ret.push_back(1);
        for (int i = 0; i < rowIndex - 1; i++)
        {
            vector<int>rem(ret);
            int m = rem.size();
            ret.clear();
            ret.push_back(1);
            for (int j = 1; j < m; j++)
            {
                ret.push_back(rem[j] + rem[j - 1]);
            }
            ret.push_back(1);
        }
        return ret;
    }
};

class Solution_119_2 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ret(rowIndex + 1, 1);
        for (int n = 1; n < rowIndex; n++)
        {
            int tmp = 1;
            for (int m = 1; m < n + 1; m++)
            {
                int num = ret[m];
                ret[m] += tmp;
                tmp = num;
            }
        }
        return ret;
    }
};