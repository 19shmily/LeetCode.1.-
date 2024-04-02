#include<iostream>
#include<vector>

using namespace std;
//
//class Solution_42 {
//    int ret;
//public:
//    int trap(vector<int>& height) {
//        ret = 0;
//        int l = 0;
//        while (l < height.size()-1)
//        {
//            int move = l + 1;
//            int h = height[l];
//            int tmp = 0;
//            int r = move;
//            while (move < height.size() - 1)
//            {
//                if (height[move] >= height[l])
//                {
//                    ret += tmp;
//                    tmp = 0;
//                    h = height[move];
//                    l = move;
//                }
//                else
//                {
//                    tmp += h - height[move];
//                }
//                r = height[move] > height[r] ? move : r;
//                move++;
//            }
//            ret += tmp - (r - l) * (height[l] - height[r]);
//            l = r;
//        }
//        return ret;
//    }
//};

class Solution_42 {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int lmax = height[l], rmax = height[r];//Ĭ����ߵ�ľ������Ԫ�أ��ұ�ľ�����ĩԪ��
        int ret = 0;
        while (r > l)
        {
            if (height[r] > height[l])//�ж�Ŀǰ����ľ��Ĵ�С
            {
                l++;//�����ߵ�С��������ָ��
                lmax = height[l] > lmax ? height[l] : lmax;//������ľ��
                if (height[r] > height[l])//������ƺ����ָ����ָԪ����ȻС���ұ����ֵ
                {
                    ret += lmax - height[l];//��Ŀǰ��ָ����ָ���е�ʢˮ��һ��������ľ��
                                            //��ȥĿǰ��ָ����ָ���е�ֵ
                                            //��������Ϊʢˮ��һ���ǽ�С���Ǹ�ľ���Ŀǰֵ�Ĳ�
                                            //��������������ľ�壬��������ָ����ָ��Ҳһ������ʢˮ���������Ľ��Ҳ��0
                                            //���û���£��Ǹ�������ˣ�һ����ʢˮ�Ĳ���
                }
                else {
                    continue;//�����ָ�����ƺ��������ľ�壬�Ǵ�ʱ��ָ����ָ��һ������ʢˮ
                             //���Ծͽ����´�ѭ��������
                }
            }
            else {//ͬ������
                r--;
                rmax = height[r] > rmax ? height[r] : rmax;
                if (height[r] < height[l])
                {
                    ret += rmax - height[r];
                }
                else {
                    continue;
                }
            }
        }
        return ret;
    }
};

//int main()
//{
//    Solution_42 test;
//    vector<int>arr;
//    arr.push_back(0);
//    arr.push_back(1);
//    arr.push_back(0);
//    arr.push_back(2);
//    arr.push_back(1);
//    arr.push_back(0);
//    arr.push_back(1);
//    arr.push_back(3);
//    arr.push_back(2);
//    arr.push_back(1);
//    arr.push_back(2);
//    arr.push_back(1);
//    cout << test.trap(arr) << endl;
//    return 0;
//}