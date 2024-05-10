#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0 && t.size() == 0) { return true; }
        int m = t.size(), j = s.size();
        int index = 0;
        for (int n = 0; n < m; n++)
        {
            if (s[index] == t[n])
            {
                index++;
            }
            if (index == j)
            {
                return true;
            }
        }
        return false;
    }
};