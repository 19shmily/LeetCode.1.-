#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution_100 {
    bool work(TreeNode* p, TreeNode* q)
    {
        if ((!p && q) || (p && !q)) { return false; }
        if (!p && !q) { return true; }
        if (p->val == q->val)
        {
            if (work(p->left, q->left) && work(p->right, q->right))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return work(p, q);
    }
};