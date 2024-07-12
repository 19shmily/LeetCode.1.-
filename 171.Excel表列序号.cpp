#include<iostream>
#include<string>

using namespace std;

class Solution_171 {
public:
    int titleToNumber(string columnTitle) {
        int ret = 0;
        int cnt = 0;
        while (!columnTitle.empty())
        {
            ret += (columnTitle.back() - '@') * pow(26, cnt++);
            columnTitle.pop_back();
        }
        return ret;
    }
};