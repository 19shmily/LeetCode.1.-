#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution_242 {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { return false; }
        unordered_map<char, int>mp;
        int m = s.size();
        for (int n = 0; n < m; n++)
        {
            mp[s[n]]++;
        }
        m = t.size();
        for (int n = 0; n < m; n++)
        {
            mp[t[n]]--;
            if (mp[t[n]] < 0) { return false; }
        }
        return true;
    }
};