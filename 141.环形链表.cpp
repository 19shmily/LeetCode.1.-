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

//¹þÏ£±í
class Solution_141_1 {
    map<ListNode*, int>warehouse;
    int size;
public:
    bool hasCycle(ListNode* head) {
        size = 0;
        while (head)
        {
            warehouse[head] = 1;
            if (size == warehouse.size())
            {
                return true;
            }
            else
            {
                size++;
                head = head->next;
            }
        }
        return false;
    }
};

//¿ìÂýÖ¸Õë
class Solution_141_2 {
    ListNode* fast;
    ListNode* slow;
public:
    bool hasCycle(ListNode* head) {
        fast = head;
        slow = head;
        while (slow && fast)
        {
            if (fast->next)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            else
            {
                return false;
            }
            if (fast == slow) { return true; }
        }
        return false;
        return false;
    }
};