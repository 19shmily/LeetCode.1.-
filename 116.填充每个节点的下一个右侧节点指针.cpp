#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
    queue<Node*>q;
    void work()
    {
        if (q.empty()) { return; }
        int m = q.size();
        for (int n = 0; n < m; n++)
        {
            auto p = q.front();
            if (p->left) { q.push(p->left); q.push(p->right); }
            q.pop();
            if (n < m - 1)
            {
                p->next = q.front();
            }
        }
        work();
        return;
    }
public:
    Node* connect(Node* root) {
        if (root) { q.push(root); work(); }
        return root;
    }
};