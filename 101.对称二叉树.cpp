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

class Solution_101 {
    bool work(TreeNode* root1, TreeNode* root2)
    {
        if (root1 == NULL)
        {
            if (root2 == NULL) { return true; }
            else { return false; }
        }
        if (root2 == NULL)
        {
            if (root1 == NULL) { return true; }
            else { return false; }
        }
        if (root1->val != root2->val)
        {
            return false;
        }
        else
        {
            if (work(root1->left, root2->right))
            {
                if (work(root1->right, root2->left))
                {
                    return true;
                }
                else { return false; }
            }
            else { return false; }
        }
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) { return true; }
        else { return work(root->left, root->right); }
    }
};