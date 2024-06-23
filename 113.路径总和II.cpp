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
 
class Solution_113 {
    vector<vector<int>>ret;
    vector<int>tmp;
    bool work(TreeNode* root, int targetSum)
    {
        if (!root)
        {
            if (!targetSum)
            {
                return true;
            }
        }
        else
        {
            tmp.push_back(root->val);
            auto flag1 = work(root->left, targetSum - root->val);
            auto flag2 = work(root->right, targetSum - root->val);
            if (flag1 && flag2) { ret.push_back(tmp); }
            tmp.pop_back();
        }
        return false;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        work(root, targetSum);
        return ret;
    }
};