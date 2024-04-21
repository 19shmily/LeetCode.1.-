#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution_322 {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>arr(amount + 1);
        int n = coins.size();
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; i++)
        {
            int minn = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (i - coins[j] < 0) { break; }
                if (arr[i - coins[j]] >= 0)
                {
                    minn = min(minn, arr[i - coins[j]]);
                }
            }
            if (minn == INT_MAX)
            {
                arr[i] = -1;
            }
            else
            {
                arr[i] = minn + 1;
            }
        }
        return arr[amount];
    }
};