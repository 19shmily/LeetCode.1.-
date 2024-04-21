#include<iostream>
#include<vector>
using namespace std;

//��ʱ
class Solution_279_1 {
    int count = 0;
    int ret = INT_MAX;
    void work(int n)
    {
        if (!n) 
        { 
            ret = ret > count ? count : ret;
            return; 
        }
        count++;
        int tmp = 1;
        while (tmp * tmp <= n)
        {
            work(n - tmp * tmp);
            tmp++;
        }
        count--;
    }
public:
    int numSquares(int n) {
        work(n);
        return ret;
    }
};

//�ٷ���⣬ֻ��˵��̬�滮ţ��
class Solution_279_2 {
public:
    int numSquares(int n) {
        vector<int> f(n + 1);//����һ��n+1�������飬Ϊ�˿��Է��ʵ�n
        for (int i = 1; i <= n; i++) {//���±�1��Ҳ��������1����ɿ�ʼö��
            int minn = INT_MAX;//��¼��Сֵ
            for (int j = 1; j * j <= i; j++) {
                minn = min(minn, f[i - j * j]);//i-j*j����˼���ǣ�ȡ����j*j�����ϲ�ѯʣ�²��ֵ���С���
            }
            f[i] = minn + 1;//ʣ�ಿ����С�������1������ǰ������С���
        }
        return f[n];
    }
};