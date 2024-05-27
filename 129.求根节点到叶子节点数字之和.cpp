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

class Solution_129 {
    int sum = 0;
    bool work(TreeNode* root, int num)
    {
        if (!root) 
        { 
            return true; 
        }
        else
        {
            num = num * 10 + root->val;
            auto res1 = work(root->left, num);
            auto res2 = work(root->right, num);
            if (res1 && res2)
            {
                sum += num;
            }
            return false;
        }
        
    }
public:
    int sumNumbers(TreeNode* root) {
        work(root, 0);
        return sum;
    }
};