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
 
class Solution_144 {
    vector<int>ret;
    void work(TreeNode* root)
    {
        if (!root) { return; }
        ret.push_back(root->val);
        work(root->left);
        work(root->right);
        return;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        work(root);
        return ret;
    }
};