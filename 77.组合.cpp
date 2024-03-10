#include<iostream>
#include<vector>

using namespace std;

class Solution_77 {
    vector<vector<int>>ret;
    vector<int>tmp;
    void work(int i, int n, int k)
    {
        if (tmp.size() == k)
        {
            ret.push_back(tmp);
            return;
        }
        for (int m = i; m <= n; m++)
        {
            tmp.push_back(m);
            work(m + 1, n, k);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        work(1, n, k);
        return ret;
    }
};

//int main()
//{
//    Solution test;
//    test.combine(4, 2);
//
//    return 0;
//}