#include<iostream>
#include<vector>
using namespace std;

class Solution_994 {
    vector<vector<int>>bad;
    int ret;
    void judg(int x, int y, vector<vector<int>>& grid)
    {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) { return; }
        if (grid[x][y] == 1)
        {
            grid[x][y] = 2;
            bad.push_back({ x,y });
        }
        else
        {
            return;
        }
    }
    void work(vector<vector<int>>& grid)
    {
        int m = bad.size();
        for (int n = 0; n < m; n++)
        {
            judg(bad[0][0] - 1, bad[0][1], grid);
            judg(bad[0][0] + 1, bad[0][1], grid);
            judg(bad[0][0], bad[0][1] - 1, grid);
            judg(bad[0][0], bad[0][1] + 1, grid);
            bad.erase(bad.begin());
        }
        ret++;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        ret = -1;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    bad.push_back({ i,j });
                }
            }
        }
        while (bad.size())
        {
            work(grid);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return ret == -1 ? 0 : ret;
    }
};