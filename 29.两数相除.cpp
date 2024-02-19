#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


//�������(δ�꣨��ʱ���� ��)
class Solution_29_my {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) { return 1; }
        if (dividend == INT_MAX)
        {
            if (divisor == 1) { return INT_MAX; }
            if (divisor == -1) { return -INT_MAX; }
        }
        if (dividend == INT_MIN)
        {
            if (divisor == 1) { return INT_MIN; }
            if (divisor == -1) { return INT_MAX; }
        }
        int ret = 0;
        int flag = -1;
        if (dividend == 0)
        {
            return 0;
        }
        else if (dividend > 0)
        {
            dividend = -dividend;
            flag = -flag;
        }
        if (divisor == 0)
        {
            return 0;
        }
        else if (divisor > 0)
        {
            divisor = -divisor;
            flag = -flag;
        }
        while (dividend <= 0)
        {
            dividend -= divisor;
            ret--;
        }
        ret++;
        return ret * flag;
    }
};


//�Ż���
class Solution_29 {
public:
    int divide(int dividend, int divisor) {
        int type = 1;
        if ((dividend < 0 && divisor>0) || (dividend > 0 && divisor < 0))
            type = -1;//�ж�������
        if (dividend > 0)
            dividend = -dividend;
        if (divisor > 0)
            divisor = -divisor;//ȫ��ת��Ϊ����
        if (dividend > divisor) return 0;//�������
        if (dividend == INT_MIN && divisor == -1) {//��1���д���
            if (type == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }
        else if (divisor == -1)
            return type * abs(dividend);
        int num = 0, temp = divisor;//������ʹ�ö��ּ���
        vector<int>arr{ temp };//�Ƚ��д��
        while (temp >= (dividend >> 1)) {
            temp <<= 1;
            arr.push_back(temp);
        }
        while (dividend <= divisor) {//���
            int max = 0, left = 0, right = arr.size() - 1;
            while (left <= right) {//����Ѱ�ң�����ֵ�����Ŀ������ڳ�����
                int mid = left + ((right - left) >> 1);
                if (arr[mid] >= dividend) {
                    max = mid;
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
            dividend -= arr[max];
            num += 1 << max;//��¼��Ŀ
        }
        return type * num;
    }
};

//int main()
//{
//    Solution_29 test;
//    int rec=test.divide(9, 8);
//    cout << rec << endl;
//
//    system("pause");
//    return 0;
//}