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

class Solution_102 {
    vector<vector<int>>ret;
    void work(TreeNode*root,int flag)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            if (ret.size() <= flag)
            {
                ret.push_back(vector<int>(1, root->val));
            }
            else
            {
                ret[flag].push_back(root->val);
            }
        }
        work(root->left, flag + 1);
        work(root->right, flag + 1);
        return;
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        work(root, 0);
        return ret;
    }
};