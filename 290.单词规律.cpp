#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution_290 {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string>mp1;
        unordered_map<string, char>mp2;
        int m = pattern.size();
        int index = 0;
        int sz = s.size();
        for (int n = 0; n < m; n++)
        {
            string tmp;
            if (index >= sz) { return false; }
            while (index < sz && s[index] != ' ')
            {
                tmp += s[index];
                index++;
            }
            index++;
            if (mp1.count(pattern[n]))
            {
                if (mp1[pattern[n]] != tmp) { return false; }
            }
            else if (mp2.count(tmp))
            {
                if (mp2[tmp] != pattern[n]) { return false; }
            }
            else
            {
                mp1[pattern[n]] = tmp;
                mp2[tmp] = pattern[n];
            }
        }
        return index >= sz ? true : false;
    }
};

int main()
{
    string s1 = "abba";
    string s2 = "dog cat cat dog";
    Solution_290 test;
    test.wordPattern(s1, s2);
    return 0;
}