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

class Solution_226 {
    void work(TreeNode* root)
    {
        if (root != NULL)
        {
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            work(root->left);
            work(root->right);
        }
        else { return; }
        return;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        work(root);
        return root;
    }
};