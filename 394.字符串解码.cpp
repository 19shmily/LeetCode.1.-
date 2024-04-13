#include<iostream>
#include<string>
using namespace std;

class Solution_394 {
    int flag = 0;
    string work(int k,int n, string s)
    {
        int m = s.size();
        int tmp = 0;
        string ret;
        string str;
        for (int i = n; i < m; i++)
        {
            if ('0' <= s[i] && s[i] <= '9')
            {
                tmp = tmp * 10 + s[i] - '0';
            }
            else if (s[i] == '[')
            {
                string recp = work(tmp, i + 1, s);
                i = flag;
                str += recp;
                tmp = 0;
            }
            else if (s[i] == ']')
            {
                while (k--)
                {
                    ret += str;
                }
                flag = i;
                return ret;
            }
            else
            {
                str.push_back(s[i]);
            }
        }
        return str;
    }
public:
    string decodeString(string s) {
        return work(1, 0, s);
    }
};