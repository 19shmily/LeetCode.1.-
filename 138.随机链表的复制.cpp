#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution_138 {
public:
    Node* copyRandomList(Node* head) {
        Node* run = head;
        Node* ret = NULL;
        unordered_map<Node*, int>mp;
        vector<Node*>arr;
        Node* front = NULL;
        int n = 0;
        while (run)
        {
            Node* tmp = new Node(run->val);
            arr.push_back(tmp);
            mp.insert(make_pair(run, n));
            if (ret == NULL)
            {
                ret = tmp;
            }
            else
            {
                front->next = tmp;
            }
            front = tmp;
            run = run->next;
            n++;
        }
        run = head;
        front = ret;
        while (run)
        {
            if (run->random != NULL)
            {
                front->random = arr[mp[run->random]];
            }
            front = front->next;
            run = run->next;
        }
        return ret;
    }
};
