#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

//��ʱ���Ѽ�
class Solution_30_1 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int num = words[0].size();
        int m = s.size() - num * words.size() + 1;
        vector<int>ret;
        for (int n = 0; n < m; n++)
        {
            vector<string>tmp(words);
            int index = n;
            while (!tmp.empty())
            {
                int flag = tmp.size();
                int move = num;
                string ss;
                while (move--)
                {
                    ss += s[index];
                    index++;
                }
                for (int i = 0; i < tmp.size(); i++)
                {
                    if (ss == tmp[i])
                    {
                        tmp.erase(tmp.begin() + i);
                        break;
                    }
                }
                if (flag == tmp.size()) { break; }
            }
            if (tmp.empty()) { ret.push_back(n); }
        }
        return ret;
    }
};

//�ٷ����
//������Ҫ��s����Ϊ�����飬ÿ�����ʵĴ�С��Ϊn����β���⣩��
//�����Ļ��ַ�����n��
//Ȼ��words.size()�����ֺõķŵ���ϣ����
//��words[0].size()Ϊ������ʼ���л�������
//����ɾ��һ��������һ��������Ϊ0��ɾ�������ж��Ƿ�Ϊ�գ�Ϊ����ѹ����ʼ�±�
//Ȼ�󻬶����ڻ���n��ͺ���
class Solution_30_2 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int m = words.size(), n = words[0].size(), ls = s.size();
        for (int i = 0; i < n && i + m * n <= ls; ++i) {
            unordered_map<string, int> differ;
            for (int j = 0; j < m; ++j) {
                ++differ[s.substr(i + j * n, n)];
            }
            for (string& word : words) {
                if (--differ[word] == 0) {
                    differ.erase(word);
                }
            }
            for (int start = i; start < ls - m * n + 1; start += n) {
                if (start != i) {
                    string word = s.substr(start + (m - 1) * n, n);
                    if (++differ[word] == 0) {
                        differ.erase(word);
                    }
                    word = s.substr(start - n, n);
                    if (--differ[word] == 0) {
                        differ.erase(word);
                    }
                }
                if (differ.empty()) {
                    res.emplace_back(start);
                }
            }
        }
        return res;
    }
};

//int main()
//{
//    Solution_30 test;
//    string s = "word";
//    vector<string>words;
//    words.push_back(s);
//    s = "good";
//    words.push_back(s);
//    s = "best";
//    words.push_back(s);
//    s = "good";
//    words.push_back(s);
//    s = "wordgoodgoodgoodbestword";
//    test.findSubstring(s, words);
//
//    return 0;
//}