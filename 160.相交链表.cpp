#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution_160 {
    vector<ListNode*>tmp;
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        while (headA)
        {
            tmp.push_back(headA);
            headA = headA->next;
        }
        while (headB)
        {
            auto recp = find(tmp.begin(), tmp.end(), headB);
            if (tmp.end()!=recp)
            {
                return (*recp);
            }
            headB = headB->next;
        }
        return NULL;
    }
};