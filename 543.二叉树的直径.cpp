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

class Solution_543 {
    int ret;
    int work(TreeNode* root)
    {
        if (root == NULL) { return 0; }
        int left = work(root->left);
        int right = work(root->right);
        ret = ret > left + right ? ret : left + right;
        return left > right ? left + 1 : right + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int tmp = work(root) - 1;
        return tmp > ret ? tmp : ret;
    }
};