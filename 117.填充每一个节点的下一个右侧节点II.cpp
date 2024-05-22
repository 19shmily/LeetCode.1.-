#include<iostream>
#include<vector>
#include<unordered_map>
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
    unordered_map<int,vector<Node*>>mp;
    void work(Node* root, int n)
    {
        if (!root) { return; }
        mp[n].push_back(root);
        work(root->left, n + 1);
        work(root->right, n + 1);
        return;
    }
public:
    Node* connect(Node* root) {
        work(root, 0);
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            int m = (*it).second.size();
            for (int n = 0; n < m - 1; n++)
            {
                (*it).second[n]->next = (*it).second[n + 1];
            }
        }
        return root;
    }
};