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
 
class Solution_222 {
    int sum = 0;
    void work(TreeNode* root)
    {
        if (!root) { return; }
        sum++;
        work(root->right);
        work(root->left);
    }
public:
    int countNodes(TreeNode* root) {
        work(root);
        return sum;
    }
};