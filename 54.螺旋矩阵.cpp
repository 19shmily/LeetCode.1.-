#include<iostream>
#include<vector>

using namespace std;

class Solution_54 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ret;
        int row = 0, col = 0;
        int up = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        int gross = matrix.size() * matrix[0].size();
        while (1)
        {
            while (col <= right)
            {
                ret.emplace_back(matrix[row][col]);
                col++;
            }
            up++;
            col--;
            row++;
            if (ret.size() == gross) { return ret; }
            while (row <= down)
            {
                ret.emplace_back(matrix[row][col]);
                row++;
            }
            right--;
            row--;
            col--;
            if (ret.size() == gross) { return ret; }
            while (col >= left)
            {
                ret.emplace_back(matrix[row][col]);
                col--;
            }
            down--;
            col++;
            row--;
            if (ret.size() == gross) { return ret; }
            while (row >= up)
            {
                ret.emplace_back(matrix[row][col]);
                row--;
            }
            left ++;
            row++;
            col++;
            if (ret.size() == gross) { return ret; }
        }
    }
};

//int main()
//{
//    Solution test;
//    vector<vector<int>>arr;
//    arr.push_back({ 1,2,3 });
//    arr.push_back({ 4,5,6 });
//    arr.push_back({ 7,8,9 });
//    vector<int>recp = test.spiralOrder(arr);
//    return 0;
//}