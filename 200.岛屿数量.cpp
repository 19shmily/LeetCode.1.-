#include<iostream>
#include<vector>
using namespace std;

class Solution_200 {
    int i;
    int j;
    int ret;
    void work(int x, int y, vector<vector<char>>& grid)
    {
        if (i == x || y == j || x < 0 || y < 0) { return; }
        if (grid[x][y] == '1')
        {
            grid[x][y] = '2';
            work(x, y + 1, grid);
            work(x, y - 1, grid);
            work(x + 1, y, grid);
            work(x - 1, y, grid);
        }
        else
        {
            return;
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        i = grid.size();
        j = grid[0].size();
        for (int n = 0; n < i; n++)
        {
            for (int m = 0; m < j; m++)
            {
                if (grid[n][m] == '1')
                {
                    work(n, m, grid);
                    ret++;
                }
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<char>>grid;
    grid.push_back({ '1','1','1','1','0'});
    grid.push_back({ '1','1','0','1','0'});
    grid.push_back({ '1','1','0','1','0'});
    grid.push_back({ '0','0','0','0','0'});
    Solution_200 test;
    test.numIslands(grid);

    return 0;
}