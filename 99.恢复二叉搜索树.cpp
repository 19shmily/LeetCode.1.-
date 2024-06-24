#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
//不理解为什么会insert到前面去
//自认为写法没问题
class Solution_99_1 {
    unordered_map<int, TreeNode*>mp1;
    map<int, TreeNode*, less<int>>mp2;
    //按道理是less<int>，但是力扣上却需要greater<int>，不理解
    void work(TreeNode* root)
    {
        if (!root) { return; }
        work(root->left);
        mp1.insert({ root->val,root });
        mp2.insert({ root->val,root });
        work(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        work(root);
        auto it2 = mp2.begin();
        for (auto it1 = mp1.begin(); it1 != mp1.end();)
        {
            if (it1->first != it2->first)
            {
                auto tmp1 = it2->first, tmp2 = it1->first;
                it1->second->val = tmp1;
                it2->second->val = tmp2;
                break;
            }
            it1++; it2++;
        }
        return;
    }
};

//官方题解，和我思路差不多
class Solution_99_2 {
public:
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    pair<int, int> findTwoSwapped(vector<int>& nums) {
        int n = nums.size();
        int index1 = -1, index2 = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] < nums[i]) {
                index2 = i + 1;
                if (index1 == -1) {
                    index1 = i;
                }
                else {
                    break;
                }
            }
        }
        int x = nums[index1], y = nums[index2];
        return { x, y };
    }

    void recover(TreeNode* r, int count, int x, int y) {
        if (r != nullptr) {
            if (r->val == x || r->val == y) {
                r->val = r->val == x ? y : x;
                if (--count == 0) {
                    return;
                }
            }
            recover(r->left, count, x, y);
            recover(r->right, count, x, y);
        }
    }

    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        pair<int, int> swapped = findTwoSwapped(nums);
        recover(root, 2, swapped.first, swapped.second);
    }
};

int main()
{
    Solution_99_1 test;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(-2);
    root->left->right = new TreeNode(2);
    test.recoverTree(root);
    return 0;
}