#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

//自己写的，有样例跑不过
//如s="aaaaaaaaaaaabbbbbcdd"，t="abcdd"
//无法跑过答案中含有t中重复字符的样例
class Solution_76_1 {
    unordered_map<char, int>mp;
    string ret;
public:
    string minWindow(string s, string t) {
        int lg = t.size();
        for (int n = 0; n < lg; n++)
        {
            mp[t[n]]++;
        }
        lg = s.size();
        int count = t.size();
        int flag = -1;
        int l = INT_MAX;
        int index = -1;
        for (int n = 0; n < lg; n++)
        {
            if (t.find(s[n]) != string::npos)
            {
                if (flag < 0) { flag = n; }
                mp[s[n]]--;
                count--;
                if (mp[s[n]] < 0)
                {
                    while (mp[s[n]] < 0)
                    {
                        if (t.find(s[flag]) != string::npos)
                        {
                            mp[s[flag]]++;
                            count++;
                        }
                        flag++;
                    }
                    while (t.find(s[flag]) == string::npos)
                    {
                        flag++;
                    }
                }
                if (count == 0)
                {
                    if (n - flag < l)
                    {
                        l = n - flag;
                        index = flag;
                    }
                }
            }
        }
        if (index >= 0)
        {
            ret.resize(l + 1);
            copy(s.begin() + index, s.begin() + index + l + 1, ret.begin());
        }
        return ret;
    }
};

//以下是官解,其实自己写的很接近官解了，都是哈希+滑动窗口
//官解通过记录重复数字的个数，和判断窗口中是否含有t来进行滑动
//如含有且在滑动左边界后依然可以含有t则滑动左边，反之滑动右边界
//每次到当时最短则更新最短长度
class Solution_76_2 {
public:
    unordered_map <char, int> ori, cnt;

    bool check() {
        for (const auto& p : ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (const auto& c : t) {
            ++ori[c];
        }

        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1, ansR = -1;

        while (r < int(s.size())) {
            if (ori.find(s[++r]) != ori.end()) {
                ++cnt[s[r]];
            }
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                if (ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]];
                }
                ++l;
            }
        }

        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};

//int main()
//{
//    Solution_76_1 test;
//    string s = "bba";
//    string t = "ab";
//    test.minWindow(s, t);
//    return 0;
//}