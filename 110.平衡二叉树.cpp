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
 
class Solution_110 {
    int work(TreeNode* root)
    {
        if (!root) { return 0; }
        int l = work(root->left);
        int r = work(root->right);
        if (l == -1 || r == -1) { return -1; }
        if (abs(l - r) > 1) { return -1; }
        return l > r ? l + 1 : r + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return work(root) == -1 ? false : true;
    }
};