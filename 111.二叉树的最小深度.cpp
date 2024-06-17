#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution_111 {
    int ret = INT_MAX;
    bool work(TreeNode* root, int cnt)
    {
        if (cnt > ret) { return false; }
        if (!root) 
        {
            return true;
        }
        bool res1 = work(root->left, cnt + 1);
        bool res2 = work(root->right, cnt + 1);
        if (res1 && res2)
        {
            ret = ret > cnt ? cnt : ret;
        }
        return false;
    }
public:
    int minDepth(TreeNode* root) {
        work(root, 1);
        return ret == INT_MAX ? 0 : ret;
    }
};