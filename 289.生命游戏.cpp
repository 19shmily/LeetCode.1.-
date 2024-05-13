#include<iostream>
#include<vector>

using namespace std;

class Solution_289 {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int j = board[0].size();
        vector<vector<int>>mood(board);
        for (int n = 0; n < m; n++)
        {
            for (int i = 0; i < j; i++)
            {
                int cnt = 0;
                if (i != 0)
                {
                    if (mood[n][i - 1]) { cnt++; }
                    if (n != 0)
                    {
                        if (mood[n - 1][i - 1]) { cnt++; }
                    }
                    if (n != m - 1)
                    {
                        if (mood[n + 1][i - 1]) { cnt++; }
                    }
                }
                if (i != j - 1)
                {
                    if (mood[n][i + 1]) { cnt++; }
                    if (n != 0)
                    {
                        if (mood[n - 1][i + 1]) { cnt++; }
                    }
                    if (n != m - 1)
                    {
                        if (mood[n + 1][i + 1]) { cnt++; }
                    }
                }
                if (n != 0 && mood[n - 1][i]) { cnt++; }
                if (n != m - 1 && mood[n + 1][i]) { cnt++; }
                if (mood[n][i])
                {
                    if (cnt < 2 || cnt > 3) { board[n][i] = 0; }
                }
                else
                {
                    if (cnt == 3) { board[n][i] = 1; }
                }
            }
        }
        return ;
    }
};

int main()
{
    Solution_289 test;
    vector<vector<int>>board;
    board.push_back({ 0,1,0 });
    board.push_back({ 0,0,1 });
    board.push_back({ 1,1,1 });
    board.push_back({ 0,0,0 });
    test.gameOfLife(board);
    return 0;
}