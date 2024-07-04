#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

//自己写的
class Solution_137_1 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        int m = nums.size();
        for (int n = 0; n < m; n++)
        {
            mp[nums[n]]++;
            if (mp[nums[n]] == 3) { mp.erase(nums[n]); }
        }
        return mp.begin()->first;
    }
};

//官解叹为观止
//作者：力扣官方题解
//链接：https ://leetcode.cn/problems/single-number-ii/solutions/746993/zhi-chu-xian-yi-ci-de-shu-zi-ii-by-leetc-23t6/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//依次确定每一个二进制位
class Solution_137_2 {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int total = 0;
            for (int num : nums) {
                total += ((num >> i) & 1);
            }
            if (total % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};

//数字电路设计
class Solution_137_3 {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int num : nums) {
            tie(a, b) = pair<int, int>{ (~a & b & num) | (a & ~b & ~num), ~a & (b ^ num) };
        }
        return b;
    }
};

//数字电路设计优化
class Solution_137_4 {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int num : nums) {
            b = ~a & (b ^ num);
            a = ~b & (a ^ num);
        }
        return b;
    }
};