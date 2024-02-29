#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class mycompara
{
public:
    bool operator() (vector<int>arr1, vector<int>arr2)const
    {
        return arr1[0] < arr2[0];
    }
};
class Solution_56 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), mycompara());
        vector<int>tmp;
        vector<vector<int>>ret;
        int flag = 0;
        int num_max = 0;
        while (flag < intervals.size())
        {
            tmp.emplace_back(intervals[flag][0]);
            num_max = intervals[flag][1];
            while (flag < intervals.size() - 1 && num_max >= intervals[flag + 1][0])
            {
                num_max = max(num_max, intervals[flag + 1][1]);
                flag++;
            }
            tmp.emplace_back(num_max);
            ret.emplace_back(tmp);
            tmp.clear();
            flag++;
        }
        return ret;
    }
};
