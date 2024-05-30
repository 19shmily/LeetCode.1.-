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
 
class BSTIterator {
    int index = -1;
    vector<int>* head = NULL;
    void work(TreeNode* root)
    {
        if (!root) { return; }
        work(root->left);
        head->push_back(root->val);
        work(root->right);
        return;
    }
public:
    BSTIterator(TreeNode* root) {
        index = -1;
        head = new vector<int>;
        work(root);
    }

    int next() {
        index++;
        return head->at(index);
    }

    bool hasNext() {
        if (head->size() - index > 1) { return true; }
        else { return false; }
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    BSTIterator test(root);
    bool res = test.hasNext();
    return 0;
}