#include<iostream>
#include<vector>
using namespace std;

//���Ķ�̬�滮
//�ǵ�һ������dp�������ǵ�һ��д��dp
//������⣬��ʵֱ��������������vector������ʡ�ռ�
class Solution_70 {
public:
    int climbStairs(int n) {
        if (n == 1) { return 1; }
        if (n == 2) { return 2; }
        vector<int>tmp;
        tmp.push_back(1);
        tmp.push_back(2);
        for (int i = 3; i <= n; i++)
        {
            tmp.push_back(tmp[0] + tmp[1]);
            tmp.erase(tmp.begin());
        }
        return tmp[1];
    }
};