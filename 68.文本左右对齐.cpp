#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution_68 {
    vector<string>ret;
    string s;
    void work(int maxWidth, int num, int n, int m, vector<string>& words)
    {
        if (m - n == 1)
        {
            s += words[n];
            int tmp = maxWidth - words[n].size();
            while (tmp--)
            {
                s += ' ';
            }
        }
        else
        {
            num -= (m - n);
            int tmp = maxWidth - num;
            int blank = tmp % (m - n - 1);
            tmp /= (m - n - 1);
            while (n < m)
            {
                s += words[n];
                int i = tmp;
                while (i-- && n != m - 1)
                {
                    s += ' ';
                }
                if (blank) { s += ' '; blank--; }
                n++;
            }
        }
        ret.push_back(s);
        s.clear();
        return;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int m = words.size();
        int n = 0;
        int num = 0;
        int flag = 0;
        while (n < m)
        {
            if (num + words[n].size() > maxWidth)
            {
                work(maxWidth, num, flag, n, words);
                flag = n;
                num = words[n].size() + 1;
            }
            else
            {
                num += (words[n].size() + 1);
            }
            n++;
        }
        while (flag < m)
        {
            s += words[flag];
            s += ' ';
            flag++;
        }
        s.pop_back();
        num = maxWidth - s.size();
        while (num--)
        {
            s += ' ';
        }
        ret.push_back(s);
        return ret;
    }
};

//int main()
//{
//    vector<string>words;
//    string s;
//    s = "What";
//    words.push_back(s);
//    s = "must";
//    words.push_back(s);
//    s = "be";
//    words.push_back(s);
//    s = "acknowledgment";
//    words.push_back(s);
//    s = "shall";
//    words.push_back(s);
//    s = "be";
//    words.push_back(s);
//    Solution_68 test;
//    test.fullJustify(words, 16);
//    return 0;
//}