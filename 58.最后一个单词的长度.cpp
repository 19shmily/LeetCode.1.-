#include<iostream>
#include<string>

using namespace std;

class Solution_58 {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        int flag = 0;
        for (int n = s.size() - 1; n >= 0; n--)
        {
            if (s[n] != ' ')
            {
                ret++;
                flag = 1;
            }
            if (s[n] == ' ' && flag) { return ret; }
        }
        return ret;
    }
};