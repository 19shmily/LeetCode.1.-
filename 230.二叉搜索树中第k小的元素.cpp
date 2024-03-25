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

class Solution_230_1 {
    vector<int>tmp;
    void work(TreeNode* root)
    {
        if (root == NULL) { return; }
        work(root->left);
        tmp.push_back(root->val);
        work(root->right);
        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        work(root);
        return tmp[k - 1];
    }
};


class Solution_230_2 {
    int count;
    int ret;
    void work(TreeNode* root)
    {
        if (root == NULL || !count) { return; }
        work(root->left);
        if (!count) { return; }
        ret = root->val;
        count--;
        work(root->right);
        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        work(root);
        return ret;
    }
};