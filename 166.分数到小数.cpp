#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


//因精度受限，最终还是没有跑完
class Solution_166_1 {
    string ret;
    string s;
    bool work(int n1,int n2)
    {
        int m = s.size();
        int index = n1;
        for (int n = n2; n < m; n++)
        {
            if (s[index] == s[n])
            { 
                index++;
                if (index == n2) { index = n1; }
            }
            else { return false; }
        }
        return true;
    }
public:
    string fractionToDecimal(int numerator, int denominator) {
        int n1 = numerator / denominator;
        long double n2 = (long double)numerator / (long double)denominator;
        if (n1 != n2)
        {
            ret = to_string(n1);
            ret += '.';
            long double num = n2 - (long double)n1;
            int cnt = 0;
            while (num != 0 && cnt++ < 19)
            {
                num *= 10;
                int tmp = num;
                s += (num + '0');
                num -= tmp;
            }
            int m = s.size();
            for (int i = 0; i < m; i++)
            {
                for (int n = i + 1; n < m; n++)
                {
                    if (work(i, n))
                    {
                        ret += '(';
                        int move = i;
                        while (move < n)
                        {
                            ret += s[move++];
                        }
                        ret += ')';
                        return ret;
                    }
                }
                ret += s[i];
            }
        }
        else
        {
            ret = to_string(n1);
        }
        return ret;
    }
};

//官方用了长除法，也就是模拟列竖式计算，都放到了整数部分
//还用了哈希表存储
//这个题还是挺麻烦的
class Solution_166_2 {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long numeratorLong = numerator;
        long denominatorLong = denominator;
        if (numeratorLong % denominatorLong == 0) {
            return to_string(numeratorLong / denominatorLong);
        }

        string ans;
        if (numeratorLong < 0 ^ denominatorLong < 0) {
            ans.push_back('-');
        }

        // 整数部分
        numeratorLong = abs(numeratorLong);
        denominatorLong = abs(denominatorLong);
        long integerPart = numeratorLong / denominatorLong;
        ans += to_string(integerPart);
        ans.push_back('.');

        // 小数部分
        string fractionPart;
        unordered_map<long, int> remainderIndexMap;
        long remainder = numeratorLong % denominatorLong;
        int index = 0;
        while (remainder != 0 && !remainderIndexMap.count(remainder)) {
            remainderIndexMap[remainder] = index;
            remainder *= 10;
            fractionPart += to_string(remainder / denominatorLong);
            remainder %= denominatorLong;
            index++;
        }
        if (remainder != 0) { // 有循环节
            int insertIndex = remainderIndexMap[remainder];
            fractionPart = fractionPart.substr(0, insertIndex) + '(' + fractionPart.substr(insertIndex);
            fractionPart.push_back(')');
        }
        ans += fractionPart;

        return ans;
    }
};

int main()
{
    Solution_166_1 test;
    test.fractionToDecimal(22, 7);
    return 0;
}