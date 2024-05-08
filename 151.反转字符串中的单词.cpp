#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution_151 {
public:
    string reverseWords(string s) {
        stack<string>stk;
        string tmp;
        int m = s.size();
        bool flag = false;
        for (int n = 0; n < m; n++)
        {
            if (s[n] == ' ') 
            {
                if (flag) 
                {
                    stk.push(tmp);
                    flag = false;
                    tmp.clear();
                }
            }
            else
            {
                tmp += s[n];
                flag = true;
            }
        }
        if (!tmp.empty())
        {
            stk.push(tmp);
            flag = false;
            tmp.clear();
        }
        while (!stk.empty())
        {
            tmp += stk.top();
            stk.pop();
            tmp += ' ';
        }
        tmp.pop_back();
        return tmp;
    }
};