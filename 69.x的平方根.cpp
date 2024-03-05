#include<iostream>

using namespace std;

//�Լ�д�����ƿ��ټ���˼ά
//���ǻ��ǱȽ�����
class Solution_69_1 {
public:
    int mySqrt(int x) {
        int n = 1;
        long long tmp = x;
        while (1)
        {
            if (tmp * tmp <= x && (tmp + 1) * (tmp + 1) > x)
            {
                return tmp;
            }
            else if (tmp * tmp < x && (tmp + 1) * (tmp + 1) <= x)
            {
                tmp += n;
                n = 1;
                continue;
            }
            tmp -= n;
            if (tmp < 0) 
            {
                tmp += n;
                n = 1;
            }
            n *= 2;
        }
    }
};

//�ٷ����Ķ��ֲ���
//��ʵ�Լ�д�˶��֣���Ϊ����û�ܹ�����Ϊ�ײ��뷨����
//�������󣬷��ֶ��ֵ��뷨��ʵû����
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};