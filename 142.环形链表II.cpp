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

class Solution {
    map<ListNode*, int>warehouse;
    int size;
public:
    ListNode* detectCycle(ListNode* head) {
        size = 0;
        while (head)
        {
            warehouse[head] = 1;
            if (size == warehouse.size())
            {
                return head;
            }
            else
            {
                size++;
                head = head->next;
            }
        }
        return NULL;
    }
};