#include<iostream>
#include<map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution_61 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) { return NULL; }
        map<int, ListNode*>tmp;
        int number = 0;
        ListNode* p = head;
        while (1)
        {
            number++;
            tmp.insert({ number, p });
            p = p->next;
            if (p == NULL)
            {
                break;
            }
        }
        k = k % number;
        if (k == 0) { return head; }
        k = number - k;
        tmp[k]->next = NULL;
        tmp[number]->next = head;
        head = tmp[k + 1];
        return head;
    }
};