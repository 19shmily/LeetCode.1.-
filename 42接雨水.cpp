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
        int lmax = height[l], rmax = height[r];//默认左边的木板是首元素，右边木板的是末元素
        int ret = 0;
        while (r > l)
        {
            if (height[r] > height[l])//判断目前左右木板的大小
            {
                l++;//如果左边的小则右移左指针
                lmax = height[l] > lmax ? height[l] : lmax;//更新左木板
                if (height[r] > height[l])//如果右移后的左指针所指元素依然小于右边最大值
                {
                    ret += lmax - height[l];//则目前左指针所指的列的盛水量一定等于左木板
                                            //减去目前左指针所指的列的值
                                            //首先是因为盛水量一定是较小的那个木板和目前值的差
                                            //其次如果更新了左木板，那现在左指针所指的也一定不能盛水，减出来的结果也是0
                                            //如果没更新，那更好理解了，一定是盛水的部分
                }
                else {
                    continue;//如果左指针右移后大于了右木板，那此时左指针所指的一定不能盛水
                             //所以就交给下次循环来操作
                }
            }
            else {//同理如上
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