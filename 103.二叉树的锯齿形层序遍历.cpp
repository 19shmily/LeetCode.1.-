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
 
class Solution_103 {
    vector<vector<int>>ret;
    void work(TreeNode* root,int index)
    {
        if (!root) { return; }
        if (index == ret.size())
        {
            ret.push_back(vector<int>(1, root->val));
        }
        else if (index % 2)
        {
            ret[index].insert(ret[index].begin(), root->val);
        }
        else
        {
            ret[index].push_back(root->val);
        }
        work(root->left, index + 1);
        work(root->right, index + 1);
        return;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        work(root, 0);
        return ret;
    }
};