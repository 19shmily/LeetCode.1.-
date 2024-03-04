#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//��ǰ����ľ��飬20���Ӳ���ȫ���ܹ���
//����dp�Ķ����޺�Ч�Եģ�����
class Solution_64 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int>arr;
        int i = grid.size(), j = grid[0].size();
        arr.resize(j);
        arr[0] = grid[0][0];
        for (int m = 1; m < j; m++)
        {
            arr[m] = arr[m - 1] + grid[0][m];
        }
        for (int n = 1; n < i; n++)
        {
            for (int m = 0; m < j; m++)
            {
                if (m == 0)
                {
                    arr[m] += grid[n][m];
                    continue;
                }
                arr[m] = min(grid[n][m] + arr[m - 1], grid[n][m] + arr[m]);
            }
        }
        return arr[j - 1];
    }
};