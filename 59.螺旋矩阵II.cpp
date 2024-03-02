#include<iostream>
#include<vector>

using namespace std;

class Solution_59 {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ret;
        vector<int>tmp;
        tmp.resize(n);
        for (int m = 0; m < n; m++)
        {
            ret.emplace_back(tmp);
        }
        int up = 0, down = n - 1, left = 0, right = n - 1;
        int row = 0, col = 0;
        int num = 1;
        while (num < n * n)
        {
            while (col < right)
            {
                ret[row][col] = num;
                num++;
                col++;
            }
            while (row < down)
            {
                ret[row][col] = num;
                num++;
                row++;
            }
            while (col > left)
            {
                ret[row][col] = num;
                num++;
                col--;
            }
            while (row > up)
            {
                ret[row][col] = num;
                num++;
                row--;
            }
            col++; row++;
            up++; down--; left++; right--;
        }
        if (n % 2 == 1)
        {
            ret[row][col] = num;
        }
        return ret;
    }
};