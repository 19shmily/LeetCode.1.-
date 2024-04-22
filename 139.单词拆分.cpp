#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;

//�����ѳ�ʱ������
//ÿ�ζ�̬�滮���᲻�ɵ��뵽����
class Solution_139_1 {
    int m = 0;
    int len = 0;
    bool work(string s, vector<string>& wordDict,int index)
    {
        if (index == len) { return true; }
        for (int n = 0; n < m; n++)
        {
            if (wordDict[n][0] == s[index])
            {
                int j = wordDict[n].size();
                int tmp = index;
                for (int i = 0; i < j; i++)
                {
                    if (wordDict[n][i] == s[tmp])
                    {
                        tmp++;
                    }
                }
                if (tmp == index + j)
                {
                    if (work(s, wordDict, tmp)) { return true; }
                }
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        m = wordDict.size();
        len = s.size();
        return work(s, wordDict, 0);
    }
};

//��̬�滮yyds
class Solution_139_2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set <string>();
        for (auto word : wordDict) {
            wordDictSet.insert(word);//ȥ��
        }

        vector <bool>dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;//dp[j]�жϽ���Ŀǰ��������ʵ�ǰj���ַ��Ƿ���Գɹ����
                    break;       //substr(i-j)�ǽ�ǰj���ַ�������ַ��س���find���ֵ��в�ѯ�Ƿ����
                }                //������������㼴true����֮false
            }
        }
        return dp[s.size()];
    }
};

//int main()
//{
//    Solution_139_1 test;
//    string s = "catsandog";
//    vector<string>wordDict;
//    wordDict.push_back("cats");
//    wordDict.push_back("dog");
//    wordDict.push_back("sand");
//    wordDict.push_back("and");
//    wordDict.push_back("cat");
//
//
//    test.wordBreak(s, wordDict);
//    return 0;
//}