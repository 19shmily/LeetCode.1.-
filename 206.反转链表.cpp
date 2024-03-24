#include<iostream>
#include<stack>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
    stack<ListNode*>tmp;
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) { return NULL; }
        while (head != NULL)
        {
            tmp.push(head);
            head = head->next;
        }
        ListNode* ret = tmp.top();
        tmp.pop();
        head = ret;
        while (!tmp.empty())
        {
            head->next = tmp.top();
            head = tmp.top();
            head->next = NULL;
            tmp.pop();
        }
        return ret;
    }
};