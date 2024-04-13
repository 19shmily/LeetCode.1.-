#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution_739 {
    stack<int>sk;
    stack<int>index;
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int m = temperatures.size();
        vector<int>ret(m, 0);
        for (int n = 0; n < m; n++)
        {
            if (sk.empty() || sk.top() >= temperatures[n])
            {
                sk.push(temperatures[n]);
                index.push(n);
            }
            else
            {
                while (!sk.empty() && sk.top() < temperatures[n])
                {
                    ret[index.top()] = n - index.top();
                    sk.pop();
                    index.pop();
                }
                sk.push(temperatures[n]);
                index.push(n);
            }
        }
        return ret;
    }
};