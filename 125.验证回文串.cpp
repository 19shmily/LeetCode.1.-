#include<iostream>
#include<string>

using namespace std;

class Solution_125 {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r)
        {
            if (!isalnum(s[l]))
            {
                l++;
                continue;
            }
            if (!isalnum(s[r]))
            {
                r--;
                continue;
            }
            if ((s[r] > 'Z' ? s[r] - 32 : s[r]) == (s[l] > 'Z' ? s[l] - 32 : s[l]))
            {
                l++;
                r--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};