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

class Solution_199 {
    vector<int>ret;
    int num;
    void work(TreeNode* root,int n)
    {
        if (root == NULL) { return; }
        if (n == num) {
            ret.push_back(root->val);
            num++;
        }
        work(root->right, n + 1);
        work(root->left, n + 1);
        return;
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        num = 0;
        work(root, 0);
        return ret;
    }
};