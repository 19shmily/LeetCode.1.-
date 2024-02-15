#include<iostream>
#include<vector>

using namespace std;



struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL)
    {
        return head;
    }
    ListNode* operate = head;
    ListNode* tmp = head;
    int flag = -1;
    while (tmp != NULL)
    {
        tmp = tmp->next;
        if (flag == n)
        {
            operate = operate->next;
            continue;
        }
        flag++;
    }
    if (n - flag == 1)
    {
        head = head->next;
        return head;
    }
    operate->next = (n == 1) ? NULL : operate->next->next;
    return head;
}
