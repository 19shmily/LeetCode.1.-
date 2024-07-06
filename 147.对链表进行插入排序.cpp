#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution_147 {
    ListNode* rear = NULL;
    ListNode* p = NULL;
    bool work(ListNode*root)
    {
        if (!root || root->val > rear->val)
        {
            p = rear;
            rear = rear->next;
            p->next = root;
            return true; 
        }
        else
        {
            if (work(root->next))
            {
                root->next = p;
                return false;
            }
        }
        return false;
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        rear = head->next;
        head->next = NULL;
        while (rear)
        {
            if (work(head))
            {
                head = p;
            }
        }
        return head;
    }
};