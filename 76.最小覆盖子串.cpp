#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

//�Լ�д�ģ��������ܲ���
//��s="aaaaaaaaaaaabbbbbcdd"��t="abcdd"
//�޷��ܹ����к���t���ظ��ַ�������
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

//�����ǹٽ�,��ʵ�Լ�д�ĺܽӽ��ٽ��ˣ����ǹ�ϣ+��������
//�ٽ�ͨ����¼�ظ����ֵĸ��������жϴ������Ƿ���t�����л���
//�纬�����ڻ�����߽����Ȼ���Ժ���t�򻬶���ߣ���֮�����ұ߽�
//ÿ�ε���ʱ����������̳���
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