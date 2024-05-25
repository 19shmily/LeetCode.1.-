#include<iostream>
#include<vector>

using namespace std;

class Solution_130 {
    int up = 0, down = 0, left = 0, right = 0;
    void work(vector<vector<char>>& board, int x, int y)
    {
        if (x < up || x >= down || y < left || y >= right)
        {
            return;
        }
        if (board[x][y] == 'X') { return; }
        else if (board[x][y] == 'O')
        {
            board[x][y] = '1';
            work(board, x - 1, y);
            work(board, x + 1, y);
            work(board, x, y - 1);
            work(board, x, y + 1);
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        down = board.size(), right = board[0].size();
        for (int x = 0; x < down; x++)
        {
            for (int y = 0; y < right; y++)
            {
                if (x == 0 || y == 0 || x == down - 1 || y == right - 1)
                {
                    work(board, x, y);
                }
            }
        }
        for (int x = 0; x < down; x++)
        {
            for (int y = 0; y < right; y++)
            {
                if (board[x][y] == 'O')
                {
                    board[x][y] = 'X';
                }
                if (board[x][y] == '1')
                {
                    board[x][y] = 'O';
                }
            }
        }
        return;
    }
};

int main()
{
    Solution_130 test;
    vector<vector<char>>board;
    board.push_back({ 'O','X','X','O','X' });
    board.push_back({ 'X','O','O','X','O' });
    board.push_back({ 'X','O','X','O','X' });
    board.push_back({ 'O','X','O','O','O' });
    board.push_back({ 'X','X','O','X','O' });
    test.solve(board);
    return 0;
}