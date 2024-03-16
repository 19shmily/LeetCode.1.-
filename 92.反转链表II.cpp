#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution_92 {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) { return head; }
        int rem = 0;
        ListNode* flag1 = NULL, * flag2 = NULL;
        ListNode* comb = head;
        ListNode* tmp = NULL;
        while (rem < right)
        {
            flag2 = comb;
            rem++;
            if (rem == left - 1)
            {
                flag1 = comb;
            }
            if (rem >= left)
            {
                ListNode* p = comb;
                comb = comb->next;
                p->next = tmp;
                tmp = p;
                continue;
            }
            comb = comb->next;
        }
        if (left > 1)
        {
            flag1->next->next = comb;
            flag1->next = flag2;
        }
        else
        {
            head->next = NULL;
            head = flag2;
        }

        return head;
    }
};