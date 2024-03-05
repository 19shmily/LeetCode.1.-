#include<iostream>
#include<string>
using namespace std;

class Solution_67 {
private:
    string ret;
    void addB(string longer,string shorter)
    {
        ret = longer;
        int n = shorter.size() - 1, m = ret.size() - 1;
        int carry = 0;
        while (m >= 0)
        {
            ret[m] += carry;
            if (n >= 0) { ret[m] += (shorter[n] - '0'); }
            else if (carry == 0) { break; }
            if (ret[m] > '1')
            {
                ret[m] -= 2;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            m--;
            n--;
        }
        if (m < 0 && carry == 1)
        {
            ret.insert(ret.begin(), '1');
        }
    }
public:
    string addBinary(string a, string b) {
        if (a.size() > b.size())
        {
            addB(a, b);
        }
        else
        {
            addB(b, a);
        }
        return ret;
    }
};

//int main()
//{
//    Solution_67 test;
//    string recpt = test.addBinary("11", "1");
//
//    return 0;
//}