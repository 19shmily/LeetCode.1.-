#include<iostream>
#include<vector>

using namespace std;

//�Լ�д�ģ�˫���ܶ��Ž�����5%
class Solution_172_1 {
public:
    int trailingZeroes(int n) {
        if (!n) { return 0; }
        int num = 1;
        int ret = 0;
        for (int i = 2; i <= n; i++)
        {
            num *= i;
            while (!(num % 10))
            {
                ret++;
                num /= 10;
            }
            num %= 100000;
        }
        return ret;
    }
};

//��ѧ��:ֻ��2*5�ſ��Եõ�һ��0��������ֻ��Ҫ��n�����Էֽ�Ϊ���ٸ�2*5�Ϳ���
//��������������5�ĸ����������������2�ĸ���
//���Կ��Խ�����������5�ĸ�����
class Solution_172_2 {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n) {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};