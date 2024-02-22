#include<iostream>
#include<vector>

using namespace std;

class Solution_36 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = { 0 };
        int col[9][9] = { 0 };
        int box[3][3][9] = {0};
        for (int n = 0; n < 9; n++)
        {
            for (int m = 0; m < 9; m++)
            {
                if (board[n][m] != '.')
                {
                    row[n][board[n][m] - '0' - 1]++;
                    col[board[n][m] - '0' - 1][m]++;
                    box[n / 3][m / 3][board[n][m] - '0' - 1]++;
                    if (row[n][board[n][m] - '0' - 1] > 1 ||
                        col[board[n][m] - '0' - 1][m] > 1 ||
                        box[n / 3][m / 3][board[n][m] - '0' - 1] > 1)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};