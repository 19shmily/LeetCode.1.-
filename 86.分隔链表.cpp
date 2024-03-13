#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution_86 {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) { return NULL; }
        ListNode* p1 = NULL, * p2 = NULL, * rear = NULL;
        ListNode* work = head;
        head = NULL;
        while (work)
        {
            if (work->val < x)
            {
                if (head == NULL)
                {
                    head = work;
                }
                else
                {
                    p1->next = work;
                }
                p1 = work;
                work = work->next;
            }
            else
            {
                if (rear == NULL)
                {
                    rear = work;
                }
                else
                {
                    p2->next = work;
                }
                p2 = work;
                work = work->next;
                p2->next = NULL;
            }
        }
        if (head == NULL)
        {
            head = rear;
        }
        else
        {
            p1->next = rear;
        }
        return head;
    }
};