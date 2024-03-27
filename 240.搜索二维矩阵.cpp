#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix[0].size();
        for (int l = 0; l < r; l++)
        {
            int up = 0, down = matrix.size() - 1;
            if (matrix[down][l] < target) { continue; }
            if (matrix[up][l] > target) { break; }
            if (matrix[up][l] <= target && target <= matrix[down][l])
            {
                while (up <= down)
                {
                    int mid = up + (down - up) / 2;
                    if (matrix[mid][l] > target)
                    {
                        down = mid - 1;
                    }
                    else if (matrix[mid][l] < target)
                    {
                        up = mid + 1;
                    }
                    else if (matrix[mid][l] == target)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};