#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution_452 {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>>tmp;
        int m = points.size();
        tmp.push_back(points[0]);
        for (int n = 1; n < m; n++)
        {
            vector<int>point = tmp.back();
            if (point[1] >= points[n][0])
            {
                tmp.pop_back();
                tmp.push_back({ max(point[0], points[n][0]),
                min(point[1], points[n][1]) });
            }
            else
            {
                tmp.push_back(points[n]);
            }
        }
        return tmp.size();
    }
};

int main()
{
    vector<vector<int>>points;
    points.push_back({ 10,10 });
    points.push_back({ 2,8 });
    points.push_back({ 1,6 });
    points.push_back({ 7,12 });
    Solution_452 test;
    test.findMinArrowShots(points);
    return 0;
}