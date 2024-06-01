#include<iostream>

using namespace std;

class Solution_191 {
public:
    int hammingWeight(int n) {
        double num = n;
        int ret = 0;
        while (n > 0)
        {
            n >>= 1;
            num /= 2;
            if (n != num) { ret++; }
            num = n;
        }
        return ret;
    }
};