#include<iostream>
#include<vector>
using namespace std;

//超时，寄了
class Solution_204_1 {
    bool work(int num)
    {
        int m = num / 2;
        for (int n = 2; n < m + 1; n++)
        {
            if (num % n == 0)
            {
                return false;
            }
        }
        return true;
    }
public:
    int countPrimes(int n) {
        int cnt = 0;
        for (int i = 2; i < n; i++)
        {
            if (work(i)) { cnt++; }
        }
        return cnt;
    }
};

//还超了，但由于没跑完，所以不知道是否正确
class Solution_204_2 {
    vector<int>rem;
    bool work(int num)
    {
        int m = rem.size();
        for (int n = 0; n < m; n++)
        {
            if (num % rem[n] == 0)
            {
                return false;
            }
        }
        rem.push_back(num);
        return true;
    }
public:
    int countPrimes(int n) {
        if (n < 3) { return 0; }
        int cnt = 0;
        rem.push_back(2);
        for (int i = 3; i < n; i++)
        {
            if (work(i)) { cnt++; }
        }
        return cnt;
    }
};

//官一也超时。。。
class Solution_204_3 {
    bool work(int num)
    {
        for (int n = 2; n * n <= num; n++) 
        {
            if (num % n == 0)
            {
                return false;
            }
        }
        return true;
    }
public:
    int countPrimes(int n) {
        int cnt = 0;
        for (int i = 2; i < n; i++)
        {
            if (work(i)) { cnt++; }
        }
        return cnt;
    }
};

//印度筛
class Solution_204_4 {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ans += 1;
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};