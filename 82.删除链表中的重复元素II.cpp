#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution_82 {
    int work(ListNode*& n)
    {
        int num = n->val;
        n = n->next;
        int count = 1;
        while (n && num == n->val)
        {
            n = n->next;
            count++;
        }
        return count;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) { return NULL; }
        ListNode* n = head, * ret = NULL;
        ListNode* rear = NULL;
        head = NULL;
        while (n != NULL)
        {
            ListNode* tmp = n;
            int recpt = work(n);
            if (recpt == 1)
            {
                if (head == NULL)
                {
                    head = tmp;
                    rear = tmp;
                    rear->next = NULL;
                }
                else
                {
                    rear->next = tmp;
                    rear = rear->next;
                    rear->next = NULL;
                }
            }
        }
        return head;
    }
};