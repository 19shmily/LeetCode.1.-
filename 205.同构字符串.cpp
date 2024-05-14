#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution_205 {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>mp1;
        unordered_map<char, char>mp2;
        int m = s.size();
        for (int n = 0; n < m; n++)
        {
            if (mp1.count(s[n]))
            {
                if (mp1[s[n]] != t[n]) { return false; }
            }
            else if (mp2.count(t[n]))
            {
                if (mp2[t[n]] != s[n]) { return false; }
            }
            else
            {
                mp1[s[n]] = t[n];
                mp2[t[n]] = s[n];
            }
        }
        return true;
    }
};