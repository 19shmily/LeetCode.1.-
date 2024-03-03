#include<iostream>
#include<vector>

using namespace std;
//自己写的，回溯，超出时间限制。。。
class Solution_62_1 {
    int number;
    void move(int row, int col, int m, int n)
    {
        if (row > m) { return; }
        if (row == m && col == n)
        {
            number++;
            return;
        }
        if (col != n)
        {
            move(row, col + 1, m, n);
        }
        move(row + 1, col, m, n);
        return;
    }
public:
    int uniquePaths(int m, int n) {
        number = 0;
        int col = 1, row = 1;
        move(col, row, m, n);
        return number;
    }
};
//因为机器到底右下角，向下几步，向右几步都是固定的,所以组合数学直接秒
class Solution_62_2 {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y) {
            ans = ans * x / y;
        }
        return ans;
    }
};
//动态规划方程：f(i , j)=f(i - 1, j) + f(i ,j - 1)
class Solution_62_3 {
public:
    int uniquePaths(int m, int n) {
        vector<int> f(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[j] += f[j - 1];
            }
        }
        return f[n - 1];
    }
};

//int main()
//{
//    Solution test;
//    int recpt = test.uniquePaths(3, 3);
//    cout << recpt << endl;
//    return 0;
//}