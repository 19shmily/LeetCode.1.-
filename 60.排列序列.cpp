#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution_60 {
    string ret;
    int arr[10] = { 1,1,2,6,24,120,720,5040,40320,362880 };
    long long factorial(int n)//计算阶乘,但本题为了降低时间复杂度，故未使用
    {
        if (n == 1) { return 1; }
        return n * factorial(n - 1);
    }
    void work(int n,int k,int index)
    {
        if (index == -1) { return; }
        int count = k / arr[index] + (k % arr[index] != 0) - 1;
        k = k - count * arr[index];
        for (int i = 1; i <= n; i++)
        {
            if (ret.find('0' + i) == string::npos)
            {
                if (count == 0)
                {
                    ret += '0' + i;
                    work(n, k, index - 1);
                    return;
                }
                count--;
            }
        }
        return;
    }
public:
    string getPermutation(int n, int k) {
        work(n, k, n - 1);
        return ret;
    }
};

int main()
{
    Solution_60 test;
    test.getPermutation(4, 9);
    return 0;
}