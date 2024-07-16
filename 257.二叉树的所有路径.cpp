#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution_257 {
    string tmp;
    vector<string>ret;
    void s_add(int n)
    {
        string s;
        int num = abs(n);
        while (num)
        {
            s.insert(s.begin(), num % 10 + '0');
            num /= 10;
        }
        if (n < 0) { s.insert(s.begin(), '-'); }
        tmp += s;
    }
    void s_sub(int n)
    {
        int cnt = 2;
        if (n < 0) { cnt++; n *= -1; }
        while (n)
        {
            n /= 10;
            cnt++;
        }
        while (cnt--)
        {
            tmp.pop_back();
        }
    }
    bool work(TreeNode* root)
    {
        if (!root) { return true; }
        tmp += "->";
        s_add(root->val);
        auto flag1 = work(root->left);
        auto flag2 = work(root->right);
        if (flag1 && flag2)
        {
            ret.push_back(tmp);
        }
        s_sub(root->val);
        return false;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) { return ret; }
        string s;
        int num = abs(root->val);
        while (num)
        {
            s.insert(s.begin(), num % 10 + '0');
            num /= 10;
        }
        if (root->val < 0) { s.insert(s.begin(), '-'); }
        tmp += s;
        auto flag1 = work(root->left);
        auto flag2 = work(root->right);
        if (flag1 && flag2)
        {
            ret.push_back(tmp);
        }
        return ret;
    }
};