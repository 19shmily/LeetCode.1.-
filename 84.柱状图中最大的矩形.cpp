#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution_84 {
    stack<int>sk;
    vector<int>index;
    int ret = INT_MIN;
public:
    int largestRectangleArea(vector<int>& heights) {
        int m = heights.size();
        for (int n = 0; n < m; n++)
        {
            int flag = -1;
            while (!sk.empty() && heights[n] < sk.top())
            {
                flag = index.back();
                int tmp = sk.top() * (n - index.back());
                index.pop_back();
                sk.pop();
                ret = ret < tmp ? tmp : ret;
            }
            if (flag != -1)
            {
                sk.push(heights[n]);
                index.push_back(flag);
            }
            else
            {
                sk.push(heights[n]);
                index.push_back(n);
            }
        }
        while (1)
        {
            int tmp = sk.top();
            sk.pop();
            if (sk.empty()) { return ret > tmp * m ? ret : tmp * m; }
            tmp = tmp * (m - index.back());
            index.pop_back();
            ret = ret < tmp ? tmp : ret;
        }
        return ret;
    }
};

//int main()
//{
//    Solution_84 test;
//    vector<int> heights;
//    heights.push_back(5);
//    heights.push_back(4);
//    heights.push_back(1);
//    //heights.push_back(3);
//    //heights.push_back(2);
//    //heights.push_back(5);
//
//    test.largestRectangleArea(heights);
//    return 0;
//}