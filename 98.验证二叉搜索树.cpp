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

class Solution_98 {
    bool work(TreeNode* root, long long l, long long r)
    {
        if (root == NULL) { return true; }
        if (root->val <= l || root->val >= r) { return false; }
        if (work(root->left,l, root->val))
        {
            if (work(root->right, root->val, r))
            {
                return true;
            }
            else { return false; }
        }
        else { return false; }
    }
public:
    bool isValidBST(TreeNode* root) {
        return work(root, LONG_MIN, LONG_MAX);
    }
};