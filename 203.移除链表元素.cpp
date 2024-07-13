#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution_203 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) { head = head->next; }
        auto front = head;
        auto ret = head;
        if (head) { head = head->next; }
        while (head)
        {
            if (head->val == val) 
            {
                front->next = NULL;
            }
            else
            {
                front->next = head;
                front = front->next;
            }
            head = head->next;
        }
        return ret;
    }
};