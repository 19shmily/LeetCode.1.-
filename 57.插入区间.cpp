#include<iostream>
#include<vector>

using namespace std;

class Solution_57 {
    vector<int>tmp;
    void find(vector<vector<int>>& intervals, vector<int>& newInterval,int n)
    {
        int num_max = 0;
        if (n && intervals[n][0] <= intervals[n - 1][1])
        {
            num_max = max(intervals[n][1], intervals[n - 1][1]);
            n--;
        }
        else if (n < intervals.size() - 1 && intervals[n][1] >= intervals[n + 1][0])
        {
            num_max = max(intervals[n][1], intervals[n + 1][1]);
        }
        else
        {
            return;
        }
        tmp.emplace_back(intervals[n][0]);
        while (n < intervals.size() - 1 && num_max >= intervals[n + 1][0])
        {
            num_max = max(num_max, intervals[n + 1][1]);
            intervals.erase(intervals.begin() + n);
        }
        intervals.erase(intervals.begin() + n);
        tmp.emplace_back(num_max);
        intervals.insert(intervals.begin() + n, tmp);
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        int left = 0, right = intervals.size() - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (intervals[mid][0] < newInterval[0])
            {
                left = mid + 1;
            }
            else if (intervals[mid][0] > newInterval[0])
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
                break;
            }
        }
        intervals.insert(intervals.begin() + left, newInterval);
        find(intervals, newInterval, left);
        return intervals;
    }
};

//int main()
//{
//    Solution_57 test;
//    vector<vector<int>>arr;
//    arr.push_back({ 0,5 });
//    arr.push_back({ 9,12 });
//    //arr.push_back({ 6,7 });
//    //arr.push_back({ 8,10 });
//    //arr.push_back({ 12,16 });
//
//
//    vector<int>tm;
//    tm.push_back(7);
//    tm.push_back(16);
//    test.insert(arr, tm);
//
//    return 0;
//}