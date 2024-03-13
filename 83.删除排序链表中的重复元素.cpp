#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution_83 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) { return NULL; }
        ListNode* n = head->next;
        ListNode* tmp1 = head;
        while (n != NULL)
        {
            if (n->val == tmp1->val)
            {
                n = n->next;
                tmp1->next = n;
            }
            else
            {
                tmp1 = tmp1->next;
            }
        }
        return head;
    }
};