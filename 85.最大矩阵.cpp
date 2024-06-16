#include<iostream>
#include<vector>

using namespace std;

class Solution_85 {
    int ret = 0;
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m1 = matrix.size();
        int m2 = matrix[0].size();
        vector<vector<int>>rem(m1, vector<int>(m2));
        for (int n1 = 0; n1 < m1; n1++)
        {
            int x = 0, y = INT_MAX;
            int mi = 0;
            vector<int>tmp;
            for (int n2 = 0; n2 < m2; n2++)
            {
                if (matrix[n1][n2] == '1')
                {
                    if (n1 == 0)
                    {
                        rem[n1][n2] = 1;
                    }
                    else
                    {
                        rem[n1][n2] = rem[n1 - 1][n2] + 1;
                    }
                    y = min(y, rem[n1][n2]);
                    tmp.push_back(y);
                }
            }
            for (int n2 = 0; n2 < m2; n2++)
            {
                int cnt = 0;
                int move = n2;
                while (move >= 0 && rem[n1][move] >= rem[n1][n2])
                {
                    move--;
                    cnt++;
                }
                move = n2;
                while (move < m2 && rem[n1][move] >= rem[n1][n2])
                {
                    move++;
                    cnt++;
                }
                cnt--;
                ret = cnt * rem[n1][n2] > ret ? cnt * rem[n1][n2] : ret;
            }
        }
        return ret;
    }
};