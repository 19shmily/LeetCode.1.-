#include<iostream>
#include<unordered_set>

using namespace std;

class Solution_202 {
public:
    bool isHappy(int n) {
        int tmp = 0;
        unordered_set<int>st;
        while (n != 1)
        {
            while (n != 0)
            {
                tmp += (n % 10) * (n % 10);
                n /= 10;
            }
            n = tmp;
            tmp = 0;
            if (st.count(n)) { return false; }
            else { st.insert(n); }
        }
        return true;
    }
};

int main()
{
    Solution_202 test;
    test.isHappy(19);
    return 0;
}