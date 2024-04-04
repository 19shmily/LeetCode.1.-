#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution_236 {
    TreeNode* ret;
    int flag;
    int num1, num2;
    int rem1, rem2;
    void work(TreeNode* root)
    {
        if (!root || flag == 2)
        {
            return;
        }
        else
        {
            if (flag == 0)
            {
                if (root->val == num1) { flag = 1; ret= root; rem1 = num1; rem2 = num2; }
                if (root->val == num2) { flag = 1; ret= root; rem1 = num2; rem2 = num1; }
            }
            else if (flag == 1)
            {
                if (root->val == rem2)
                {
                    flag = 2;
                }
            }
            work(root->left);
            if (flag == 1 && ret == root->left) { ret = root; }
            work(root->right);
            if (flag == 1 && ret == root->right) { ret = root; }
        }
        return;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        num1 = p->val;
        num2 = q->val;
        ret = NULL;
        flag = 0;
        work(root);
        return ret;
    }
};