#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using  namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution_107 {
    vector<vector<int>>ret;
    queue<TreeNode*>q;
    int index = 0;
    void work()
    {
        if (q.empty()) { return; }
        int m = q.size();
        ret.push_back(vector<int>());
        for (int n = 0; n < m; n++)
        {
            if (q.front()->left)
            {
                q.push(q.front()->left);
                ret[index].push_back(q.front()->left->val);
            }
            if (q.front()->right)
            {
                q.push(q.front()->right);
                ret[index].push_back(q.front()->right->val);
            }
            q.pop();
        }
        index++;
        work();
        return;
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) { return ret; }
        ret.push_back(vector<int>(1,root->val));
        q.push(root);
        index++;
        work();
        ret.pop_back();
        reverse(ret.begin(), ret.end());
        return ret;
    }
};