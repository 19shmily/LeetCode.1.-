#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution_74 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size() - 1;
        int flag = matrix[0].size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] > target)
            {
                right = mid - 1;
            }
            else if (matrix[mid][flag] < target)
            {
                left = mid + 1;
            }
            else
            {
                left = mid;
                break;
            }
        }
        return binary_search(matrix[left].begin(), matrix[left].end(), target);
    }
};