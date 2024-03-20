#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution_108 {
    TreeNode* ret;
    void work(int head, int rear, vector<int>& nums, TreeNode* tmp, int flag)
    {
        if (head > rear) { return; }
        int mid = head + (rear - head) / 2;
        TreeNode* p = new TreeNode(nums[mid]);
        if(flag == 0)
        {
            tmp->left = p;
        }
        else
        {
            tmp->right = p;
        }
        work(head, mid - 1, nums, p, 0);
        work(mid + 1, rear, nums, p, 1);
        return;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int mid = (nums.size() - 1 - 0) / 2;
        ret = new TreeNode(nums[mid]);
        work(0, mid - 1, nums, ret, 0);
        work(mid + 1, nums.size() - 1, nums, ret, 1);
        return ret;
    }
};

//int main()
//{
//    vector<int>nums;
//    nums.push_back(0);
//    nums.push_back(1);
//    nums.push_back(2);
//    nums.push_back(3);
//    nums.push_back(4);
//    nums.push_back(5);
//    Solution_108 test;
//    test.sortedArrayToBST(nums);
//    return 0;
//}