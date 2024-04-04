#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

class Solution_439 {
    vector<long long>front;
    int VAL;
    int ret = 0;
    void all_add(int num)
    {
        int m = front.size();
        for (int n = 0; n < m; n++)
        {
            front[n] += num;
        }
        front.push_back(num);
        return;
    }
    void all_dir(int num)
    {
        int m = front.size();
        for (int n = 0; n < m; n++)
        {
            front[n] -= num;
        }
        front.pop_back();
        return;
    }
    void work(TreeNode* root)
    {
        if (root)
        {
            all_add(root->val);
            ret += count(front.begin(), front.end(), VAL);
            work(root->left);
            work(root->right);
            all_dir(root->val);
            return;
        }
        else
        {
            return;
        }
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        VAL = targetSum;
        work(root);
        return ret;
    }
};