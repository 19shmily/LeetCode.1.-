#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


//����������
//���ߣ����۹ٷ����
//���ӣ�https ://leetcode.cn/problems/scramble-string/solutions/724718/rao-luan-zi-fu-chuan-by-leetcode-solutio-8r9t/
class Solution {
private:
    // ���仯�����洢״̬������
    // -1 ��ʾ false��1 ��ʾ true��0 ��ʾδ����
    int memo[30][30][31];
    string s1, s2;

public:
    bool checkIfSimilar(int i1, int i2, int length) {
        unordered_map<int, int> freq;
        for (int i = i1; i < i1 + length; ++i) {
            ++freq[s1[i]];
        }
        for (int i = i2; i < i2 + length; ++i) {
            --freq[s2[i]];
        }
        if (any_of(freq.begin(), freq.end(), [](const auto& entry) {return entry.second != 0; })) {
            return false;
        }
        return true;
    }

    // ��һ���ַ����� i1 ��ʼ���ڶ����ַ����� i2 ��ʼ���Ӵ��ĳ���Ϊ length���Ƿ��г
    bool dfs(int i1, int i2, int length) {
        if (memo[i1][i2][length]) {
            return memo[i1][i2][length] == 1;
        }

        // �ж������Ӵ��Ƿ����
        if (s1.substr(i1, length) == s2.substr(i2, length)) {
            memo[i1][i2][length] = 1;
            return true;
        }

        // �ж��Ƿ�����ַ� c �������Ӵ��г��ֵĴ�����ͬ
        if (!checkIfSimilar(i1, i2, length)) {
            memo[i1][i2][length] = -1;
            return false;
        }

        // ö�ٷָ�λ��
        for (int i = 1; i < length; ++i) {
            // �����������
            if (dfs(i1, i2, i) && dfs(i1 + i, i2 + i, length - i)) {
                memo[i1][i2][length] = 1;
                return true;
            }
            // ���������
            if (dfs(i1, i2 + length - i, i) && dfs(i1 + i, i2, length - i)) {
                memo[i1][i2][length] = 1;
                return true;
            }
        }

        memo[i1][i2][length] = -1;
        return false;
    }

    bool isScramble(string s1, string s2) {
        memset(memo, 0, sizeof(memo));
        this->s1 = s1;
        this->s2 = s2;
        return dfs(0, 0, s1.size());
    }
};