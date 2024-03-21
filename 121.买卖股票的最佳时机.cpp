#include<iostream>
#include<vector>

using namespace std;

class Solution_121 {
    int mmin;
    int ret;
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) { return 0; }
        mmin = prices[0];
        ret = 0;
        for (auto it = prices.begin() + 1; it != prices.end(); it++) {
            ret = *it - mmin < ret ? ret : *it - mmin;
            mmin = mmin > *it ? *it : mmin;
        }
        return ret;
    }
};