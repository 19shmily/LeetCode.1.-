#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution_168 {
public:
    string convertToTitle(int columnNumber) {
        string ret;
        while (columnNumber > 0) {
            int tmp = (columnNumber - 1) % 26;
            ret += tmp + 'A';
            columnNumber = (columnNumber - tmp) / 26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main()
{
    Solution_168 test;
    test.convertToTitle(1);
    return 0;
}