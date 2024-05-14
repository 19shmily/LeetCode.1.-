#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class Solution_382 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>mp;
        int m = magazine.size();
        for (int n = 0; n < m; n++)
        {
            mp[magazine[n]]++;
        }
        m = ransomNote.size();
        for (int n = 0; n < m; n++)
        {
            mp[ransomNote[n]]--;
            if (mp[ransomNote[n]] < 0) { return false; }
        }
        return true;
    }
};