#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void find(vector<vector<int>>&ret, vector<int>& tmp, vector<int>& candidates, int mem,int pos)
{
    if (mem == 0)
    {
        ret.push_back(tmp);
        return;
    }
    for (int i = pos; i < candidates.size(); i++)
    {
        int num1 = mem / candidates[i];
        if (num1 == 0) 
        {
            return; 
        }
        int num2 = num1;
        while (num1--) 
        { 
            tmp.push_back(candidates[i]); 
            mem -= (mem / candidates[i] - num1) * candidates[i];
            find(ret, tmp, candidates, mem, i + 1);
        }
        while (num2--)
        {
            tmp.pop_back();
            mem += candidates[i];
        }
    }
}

class Solution_39 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>tmp;
        vector<vector<int>>ret;
        find(ret, tmp, candidates, target, 0);
        return ret;
    }
};

//int main()
//{
//    Solution_39 test;
//    vector<int>arr;
//    arr.push_back(2);
//    arr.push_back(3);
//    arr.push_back(6);
//    arr.push_back(7);
//    test.combinationSum(arr, 7);
//
//    system("pause");
//    return 0;
//}