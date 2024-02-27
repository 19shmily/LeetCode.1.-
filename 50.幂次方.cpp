#include<iostream>

using namespace std;

class Solution_50 {
    double fast_power(double x, long long n)
    {
        if (n == 0) { return 1; }
        double tmp = fast_power(x, n / 2);
        return n % 2 == 1 ? tmp * tmp * x : tmp * tmp;
    }
public:
    double myPow(double x, int n) {
        double ret;
        long long m = n;
        return n > 0 ? fast_power(x, m) : 1 / fast_power(x, -m);
    }
};