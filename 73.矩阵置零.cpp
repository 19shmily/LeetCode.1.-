#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class my_pr
{
public:
    bool operator()(int a)
    {
        return a != 0;
    }
};
class Solution_73 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        multimap<int, int>tmp;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    tmp.insert({ i,j });
                    for (int a = i - 1; a >= 0; a--)
                    {
                        matrix[a][j] = 0;
                    }
                }
                for (auto it = tmp.begin(); it != tmp.end(); it++)
                {
                    if ((*it).second == j)
                    {
                        matrix[i][j] = 0;
                        break;
                    }
                }
            }
        }
        for (auto it = tmp.begin(); it != tmp.end(); it++)
        {
            replace_if(matrix[(*it).first].begin(), matrix[(*it).first].end(), my_pr(), 0);
        }
        return;
    }
};