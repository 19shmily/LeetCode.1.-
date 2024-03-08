#include<iostream>
#include<string>
#include<vector>
using namespace std;

//�����Լ���dp̫����
//���������ʱ���������Ȼ���Լ�������⣬���Ǹо�����ȥд����д������
class Solution_72 {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // ��һ���ַ���Ϊ�մ�
        if (n * m == 0) return n + m;

        // DP ����
        vector<vector<int>> D(n + 1, vector<int>(m + 1));

        // �߽�״̬��ʼ��
        for (int i = 0; i < n + 1; i++) {
            D[i][0] = i;
        }
        for (int j = 0; j < m + 1; j++) {
            D[0][j] = j;
        }

        // �������� DP ֵ
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                int left = D[i - 1][j] + 1;
                int down = D[i][j - 1] + 1;
                int left_down = D[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) left_down += 1;
                D[i][j] = min(left, min(down, left_down));

            }
        }
        return D[n][m];
    }
};
