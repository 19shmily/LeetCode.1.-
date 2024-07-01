#include<iostream>
#include<vector>

using namespace std;

//回溯已超时
class Solution_120_1 {
    int ret = INT_MAX;
    void work(vector<vector<int>>& triangle, int x, int y, int sum)
    {
        if (y == triangle[x].size()) { return; }
        sum += triangle[x][y];
        if (x == triangle.size() - 1)
        {
            ret = ret > sum ? sum : ret;
            return;
        }
        work(triangle, x + 1, y, sum);
        work(triangle, x + 1, y + 1, sum);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        work(triangle, 0, 0, 0);
        return ret;
    }
};

//应该也算是动态规划，但是感觉也有点贪心的意思了
class Solution_120_2 {
    void work(vector<vector<int>>& triangle, int x)
    {
        if (x == 0) { return; }
        int m = triangle[x - 1].size();
        for (int n = 0; n < m; n++)
        {
            triangle[x - 1][n] += min(triangle[x][n], triangle[x][n + 1]);
        }
        work(triangle, x - 1);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        work(triangle, triangle.size() - 1);
        return triangle[0][0];
    }
};