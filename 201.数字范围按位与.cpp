#include<iostream>
#include<vector>

using namespace std;

//6446/8270
//有一定的可用性，但是由于有的刚好发生进位，所以不行
//如(3,4)
class Solution_201_1 {
    int ret = 0;
    vector<int>arr;
    void work(int num,int& sz)
    {
        int tmp = 0;
        while (num >= pow(2, tmp))
        {
            tmp++;
        }
        tmp--;
        sz = tmp + 1;
        arr.resize(sz, 0);
        while (num)
        {
            if (num >= pow(2, tmp))
            {
                arr[tmp] = 1;
                num -= pow(2, tmp);
            }
            tmp--;
        }
    }
public:
    int rangeBitwiseAnd(int left, int right) {
        int sz1 = 0;
        int sz2 = 0;
        work(left, sz1);
        work(right, sz2);
        int tmp = 0;
        while (pow(2, tmp) <= right - left)
        {
            tmp++;
        }
        for (int n = tmp; n < sz1; n++)
        {
            if (arr[n]) { ret += pow(2, n); }
        }
        return ret;
    }
};

class Solution_201_2 {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        // 找到公共前缀
        while (left < right) {
            left >>= 1;
            right >>= 1;
            ++shift;
        }
        return left << shift;
    }
};

class Solution_201_3 {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            right = right & (right - 1);
        }
        return right;
    }
};

int main()
{
    Solution_201_2 test;
    test.rangeBitwiseAnd(9, 13);

    return 0;
}