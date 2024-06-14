#include<iostream>
#include<string>

using namespace std;

class Solution_65 {
public:
    bool isNumber(string s) {
        int m = s.size();
        bool symbol_flag = false;
        bool number_flag = false;
        bool point_flag = false;
        bool e_flag = false;
        for (int n = 0; n < m; n++)
        {
            if (s[n] >= '0' && s[n] <= '9')
            {
                number_flag = true;
            }
            else if (s[n] == '+' || s[n] == '-')
            {
                if (number_flag||point_flag) { return false; }
                if (symbol_flag) { return false; }
                else { symbol_flag = true; }
            }
            else if (s[n] == 'e' || s[n] == 'E')
            {
                if (e_flag) { return false; }
                if (!number_flag) { return false; }
                number_flag = false;
                symbol_flag = false;
                point_flag = false;
                e_flag = true;
            }
            else if (s[n] == '.')
            {
                if (e_flag || (!number_flag && n == m - 1)) { return false; }
                if (point_flag) { return false; }
                else { point_flag = true; }
            }
            else
            {
                return false;
            }
        }
        return number_flag ? true : false;
    }
};