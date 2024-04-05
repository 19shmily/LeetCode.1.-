#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

class Solution_124 {
    int ret;
    int work(TreeNode* root)
    {
        if (root)
        {
            int tmp1 = work(root->left);
            int tmp2 = work(root->right);
            int sum = tmp1 + tmp2 + root->val;
            ret = sum > ret ? sum : ret;
            if (tmp1>tmp2)
            {
                return tmp1 + root->val > 0 ? tmp1 + root->val : 0;
            }
            else
            {
                return tmp2 + root->val > 0 ? tmp2 + root->val : 0;
            }
        }
        else
        {
            return 0;
        }
    }
public:
    int maxPathSum(TreeNode* root) {
        ret = INT_MIN;
        work(root);
        return ret;
    }
};