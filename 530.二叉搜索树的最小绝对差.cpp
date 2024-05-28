#include<iostream>
#include<set>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution_530_1 {
    set<int>st;
    void work(TreeNode* root)
    {
        if (!root) { return; }
        st.insert(root->val);
        work(root->right);
        work(root->left);
        return;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        work(root);
        int ret = INT_MAX;
        for (auto it = ++st.begin(); it != st.end(); it++)
        {
            auto tmp = it;
            tmp--;
            ret = min(*it - *tmp, ret);
        }
        return ret;
    }
};

//官方题解
//二叉搜索树中序遍历得到的值序列是递增有序的,太牛了！
class Solution_530_1 {
public:
    void dfs(TreeNode* root, int& pre, int& ans) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, pre, ans);
        if (pre == -1) {
            pre = root->val;
        }
        else {
            ans = min(ans, root->val - pre);
            pre = root->val;
        }
        dfs(root->right, pre, ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX, pre = -1;
        dfs(root, pre, ans);
        return ans;
    }
};