#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution_438 {
    unordered_map<char, int>home;
    vector<int>ret;
public:
    vector<int> findAnagrams(string s, string p) {
        for (int n = 0; n < p.size(); n++)
        {
            home[p[n]] += 1;
        }
        int l = 0;
        unordered_map<char, int>tmp;
        int count = 0;
        for (int n = 0; n < s.size(); n++)
        {
            if (home.count(s[n]))
            {
                count++;
                tmp[s[n]] += 1;
                while(tmp[s[n]] > home[s[n]])
                {
                    tmp[s[l]]--;
                    l++;
                    count--;
                }
                if (count == p.size())
                {
                    ret.push_back(l);
                    tmp[s[l]]--;
                    l++;
                    count--;
                }
            }
            else
            {
                tmp.clear();
                count = 0;
                l = n + 1;
            }
        }
        return ret;
    }
};

//int main()
//{
//    string s = "abab";
//    string p = "ab";
//    Solution_438 test;
//    test.findAnagrams(s, p);
//    return 0;
//}