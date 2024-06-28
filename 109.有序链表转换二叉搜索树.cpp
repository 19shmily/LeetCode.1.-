#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
  
class Solution_109 {
    vector<int>rem;
    vector<int>arr;
    TreeNode* work(int l, int r)
    {
        if (r < l) { return NULL; }
        int m = l + (r - l) / 2;
        TreeNode* tmp = new TreeNode(rem[m]);
        tmp->left = work(l, m - 1);
        tmp->right = work(m + 1, r);
        return tmp;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) { return NULL; }
        while (head)
        {
            rem.push_back(head->val);
            head = head->next;
        }
        return work(0, rem.size() - 1);
    }
};
