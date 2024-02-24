#include<iostream>
#include<algorithm>
#include<string>

using namespace std;


class Solution_43 {
    string ret;
    void insert(int num, int index)
    {
        int tmp = ret[index] - 48;
        tmp += num;
        int carry = tmp/10;
        tmp %= 10;
        ret[index] = tmp + 48;
        if (carry != 0)
        {
            insert(carry, index - 1);
        }
    }
public:
    string multiply(string num1, string num2) {
        if ((num1.size() == 1 && num1[0] == '0') || (num2.size() == 1 && num2[0] == '0'))
        {
            ret.push_back('0'); 
            return ret;
        }
        ret.resize(num1.size() + num2.size(), '0');
        for (int n = num1.size() - 1; n >= 0; n--)
        {
            int tmp = num1[n] - 48;
            int carry = 0;
            for (int m = num2.size() - 1; m >= 0; m--)
            {
                int product = tmp * (num2[m] - 48);
                carry = product / 10;
                product %= 10;
                insert(product, n + m + 1);
                insert(carry, n + m);
            }
        }
        if (ret[0] == '0') { ret.erase(0, 1); }
        return ret;
    }
};

//int main()
//{
//    Solution_43 test;
//    string num1("123");
//    string num2("456");
//    string rect = test.multiply(num1, num2);
//
//    system("pause");
//    return 0;
//}