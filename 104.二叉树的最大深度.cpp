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

class Solution_104 {
    int ret;
    void work(TreeNode* root,int count)
    {
        if (root != NULL)
        {
            count++;
            ret = ret > count ? ret : count;
            work(root->left, count);
            work(root->right, count);
        }
        else
        {
            return;
        }
        return;
    }
public:
    int maxDepth(TreeNode* root) {
        ret = 0;
        work(root, 0);
        return ret;
    }
};