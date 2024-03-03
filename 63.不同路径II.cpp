#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//官方题解，有点累，看懂了，没自己敲
class Solution_63 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector <int> f(m);

        f[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    f[j] = 0;
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                    f[j] += f[j - 1];
                }
            }
        }

        return f.back();
    }
};

//int main()
//{
//    vector<vector<int>>tmp;
//    tmp.push_back({ 0,1 });
//    tmp.push_back({ 1,0 });
////    tmp.push_back({ 0,0,0 });
//    Solution_63 test;
//    int recpt = test.uniquePathsWithObstacles(tmp);
//    cout << recpt << endl;
//
//    return 0;
//}