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

class Solution_114 {
    TreeNode* rear;
public:
     void work(TreeNode* root) {
        if (!root) { return ; }
        rear = root;
        TreeNode* tmp = root->right;
        rear->right = root->left;
        rear->left = NULL;
        work(rear->right);
        rear->right = tmp;
        work(tmp);
        return;
    }
public:
    void flatten(TreeNode* root) {
        work(root);
    }
};