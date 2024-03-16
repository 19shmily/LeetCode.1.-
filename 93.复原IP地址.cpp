#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution_93 {
    string tmp;
    vector<string>ret;
    int count;
    void work(string s,int n)
    {
        if (count == 4)
        {
            if (n != s.size())
            {
                return;
            }
            else
            {
                ret.push_back(tmp);
            }
        }
        if (n == s.size())
        {
            return;
        }
        if (count != 0)
        {
            tmp.push_back('.');
        }
        count++;
        int num = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i > 0 && s[n - i] == '0') { break; }
            num = num * 10 + (s[n] - '0');
            tmp.push_back(s[n]);
            n++;
            if (n > s.size() || num > 255) { break; }
            work(s, n);
        }
        if (count == 1) { return; }
        while (tmp.back() != '.')
        {
            tmp.pop_back();
        }
        tmp.pop_back();
        count--;
        return;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        work(s, 0);
        return ret;
    }
};

//int main()
//{
//    Solution_93 test;
//    string a = "101023";
//    test.restoreIpAddresses(a);
//    
//    return 0;
//}