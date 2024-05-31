#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution_133 {
    unordered_map<int, Node*>rem;
    void work(Node*root,Node* node)
    {
        if (!rem.count(node->val))
        {
            Node* tmp = new Node(node->val);
            rem.insert({ node->val, tmp });
            root->neighbors.push_back(tmp);
            for (auto it = node->neighbors.begin(); it != node->neighbors.end(); it++)
            {
                work(tmp, *it);
            }
        }
        else
        {
            root->neighbors.push_back(rem[node->val]);
        }
        return;
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) { return NULL; }
        Node* ret = new Node(node->val);
        rem.insert({ node->val,ret });
        for (auto it = node->neighbors.begin(); it != node->neighbors.end(); it++)
        {
            work(ret, *it);
        }
        return ret;
    }
};