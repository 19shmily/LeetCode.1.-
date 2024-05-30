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
 
class Solution_637 {
    vector<double>arr;
    vector<double>count;
    void work(TreeNode* root, int index)
    {
        if (!root) { return; }
        if (arr.size() == index)
        {
            arr.push_back(root->val);
            count.push_back(1);
        }
        else
        {
            arr[index] += root->val;
            count[index]++;
        }
        work(root->left, index + 1);
        work(root->right, index + 1);
        return;
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        work(root, 0);
        vector<double>ret;
        int m = arr.size();
        for (int n = 0; n < m; n++)
        {
            ret.push_back(arr[n] / count[n]);
        }
        return ret;
    }
};