#include<iostream>
#include<map>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution_148 {
    multimap<int, ListNode*>dic;
public:
    ListNode* sortList(ListNode* head) {
        while (head)
        {
            dic.insert({ head->val,head });
            head = head->next;
        }
        head = NULL;
        ListNode* front;
        for (auto it = dic.begin(); it != dic.end(); it++)
        {
            if (!head)
            {
                head = (*it).second;
            }
            else
            {
                front->next = (*it).second;
            }
            front = (*it).second;
            front->next = NULL;
        }
        return head;
    }
};