#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int ret = 0;
        for (int n = citations.size() - 1; n >= 0; n--)
        {
            if (citations[n] >= ret + 1)
            {
                ret++;
            }
            else
            {
                return ret;
            }
        }
        return ret;
    }
};