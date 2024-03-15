#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

//想了好久自己没写出来
//最后看了题解
//觉得讲的很好，最后原题解也附在了后面
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
//作者：Krahets
//链接：https ://leetcode.cn/problems/gray-code/solutions/13637/gray-code-jing-xiang-fan-she-fa-by-jyd/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。