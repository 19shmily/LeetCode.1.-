#include<iostream>
#include<vector>

using namespace std;

class Solution_48 {
    int tmp = 0;
    void up_to_right(vector<vector<int>>& matrix, int row, int col, int n)
    {
        tmp = matrix[col][n - row];
        matrix[col][n - row] = matrix[row][col];
        matrix[row][col] = tmp;
        return;
    }
    void right_to_down(vector<vector<int>>& matrix, int row, int col, int n)
    {
        tmp = matrix[n - row][n - col];
        matrix[n - row][n - col] = matrix[row][col];
        matrix[row][col] = tmp;
        return;
    }
    void down_to_left(vector<vector<int>>& matrix, int row, int col, int n)
    {
        tmp = matrix[n - col][row];
        matrix[n - col][row] = matrix[row][col];
        matrix[row][col] = tmp;
        return;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size() - 1;
        int row = 0, col = 0;
        while(1)
        {
            if (row > n / 2) { return; }
            if (col == n - row)
            {
                row++;
                col = row;
                continue;
            }
            up_to_right(matrix, row, col, n);
            right_to_down(matrix, row, col, n);
            down_to_left(matrix, row, col, n);
            col++;
        }
    }
};

//int main()
//{
//    Solution_48 test;
//    vector<vector<int>>tmp;
//    tmp.push_back({ 1,2,3 });
//    tmp.push_back({ 4,5,6 });
//    tmp.push_back({ 7,8,9 });
//    test.rotate(tmp);
//    return 0;
//}