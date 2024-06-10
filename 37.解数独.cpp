#include<iostream>
#include<vector>
using namespace std;

//刷了将近200道再做这道题，一次就AC了
class Solution_37 {
    vector<vector<int>>row;
    vector<vector<int>>col;
    vector<vector<int>>little;
    bool find(vector<vector<char>>& board)
    {
        for (int n = 0; n < 9; n++)
        {
            for (int i = 0; i < 9; i++)
            {
                if (board[n][i] == '.')
                {
                    if (!fill(board, n, i)) { return false; }
                    else { return true; }
                }
            }
        }
        return true;
    }
    bool fill(vector<vector<char>>& board, int x, int y)
    {
        for (int n = 0; n < 9; n++)
        {
            if (!row[x][n] && !col[y][n] && !little[(x / 3) * 3 + y / 3][n])
            {
                row[x][n] = 1;
                col[y][n] = 1;
                little[(x / 3) * 3 + y / 3][n] = 1;
                board[x][y] = '1' + n;
                if (!find(board))
                {
                    row[x][n] = 0;
                    col[y][n] = 0;
                    little[(x / 3) * 3 + y / 3][n] = 0;
                    board[x][y] = '.';
                }
                else { return true; }
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int n = 0; n < 9; n++)
        {
            row.push_back(vector<int>(9, 0));
            col.push_back(vector<int>(9, 0));
            if (!(n % 3))
            {
                little.push_back(vector<int>(9, 0));
                little.push_back(vector<int>(9, 0));
                little.push_back(vector<int>(9, 0));
            }
            for (int i = 0; i < 9; i++)
            {
                if (board[n][i] != '.')
                {
                    row[n][board[n][i] - '1'] = 1;
                    little[(n / 3) * 3 + i / 3][board[n][i] - '1'] = 1;
                }
                if (board[i][n] != '.')
                {
                    col[n][board[i][n] - '1'] = 1;
                }
            }
        }
        find(board);
        return;
    }
};

int main()
{
    Solution_37 test;
    vector<vector<char>>board;
    board.push_back({ '5','3','.','.' ,'7' ,'.' ,'.' ,'.' ,'.' });
    board.push_back({ '6','.','.','1' ,'9' ,'5' ,'.' ,'.' ,'.' });
    board.push_back({ '.','9','8','.' ,'.' ,'.' ,'.' ,'6' ,'.' });
    board.push_back({ '8','.','.','.' ,'6' ,'.' ,'.' ,'.' ,'3' });
    board.push_back({ '4','.','.','8' ,'.' ,'3' ,'.' ,'.' ,'1' });
    board.push_back({ '7','.','.','.' ,'2' ,'.' ,'.' ,'.' ,'6' });
    board.push_back({ '.','6','.','.' ,'.' ,'.' ,'2' ,'8' ,'.' });
    board.push_back({ '.','.','.','4' ,'1' ,'9' ,'.' ,'.' ,'5' });
    board.push_back({ '.','.','.','.' ,'8' ,'.' ,'.' ,'7' ,'9' });
    test.solveSudoku(board);
    return 0;
}