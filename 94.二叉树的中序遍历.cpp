#include<iostream>
#include<vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution_94 {
    vector<int>ret;
    void work(TreeNode* root)
    {
        if (root != NULL)
        {
            work(root->left);
            ret.push_back(root->val);
            work(root->right);
        }
        else
        {
            return;
        }
        return;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        work(root);
        return ret;
    }
};