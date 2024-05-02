#include<iostream>
#include<vector>
using namespace std;

class Solution_122 {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        int sum = 0;
        for (int n = 1; n < m; n++)
        {
            if (prices[n] >= prices[n - 1])
            {
                sum += prices[n] - prices[n - 1];
            }
        }
        return sum;
    }
};