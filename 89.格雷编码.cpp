#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

//���˺þ��Լ�ûд����
//��������
//���ý��ĺܺã����ԭ���Ҳ�����˺���
class Solution_89 {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);

        int head = 1;
        for (int i = 0; i < n; i++) {
            for (int j = res.size() - 1; j >= 0; j--) {
                res.push_back(head + res[j]);
            }
            head <<= 1;
        }
        return res;
    }
};
//
//���ߣ�Krahets
//���ӣ�https ://leetcode.cn/problems/gray-code/solutions/13637/gray-code-jing-xiang-fan-she-fa-by-jyd/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������