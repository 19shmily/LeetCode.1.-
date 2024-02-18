#include<iostream>

using namespace std;

//两两交换链表中的节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution_24 {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !(head->next))
        {
            return head;
        }
        ListNode* first = head;
        ListNode* ret = NULL;
        ListNode* tmp = NULL;
        int flag = 0;
        int judg = 0;
        while (head)
        {
            flag++;
            judg++;
            if (judg == 2)
            {
                ret = head;
                tmp = head;
                head = head->next;
                tmp->next = first;
                tmp = first;
                continue;
            }
            if (flag > 2 && flag % 2)//每组第一个数
            {
                first = head;
                head = head->next;
                continue;
            }
            else if (flag > 2 && !(flag % 2))
            {
                tmp->next = head;
                tmp = head;
                head = head->next;
                tmp->next = first;
                tmp = first;
                continue;
            }
            head = head->next;
        }
        if (flag % 2)
        {
            tmp->next = first;
        }
        else
        {
            tmp->next = NULL;
        }
        return ret;
    }
};

//两两交换链表中的节点的main函数
//int main()
//{
//    Solution_24 test;
//    ListNode* h = new ListNode;
//    h->val = 1;
//    ListNode* tp = h;
//    //tp->next= new ListNode;
//    //tp = tp->next;
//    //tp->val = 2;
//    //tp->next = new ListNode;
//    //tp = tp->next;
//    //tp->val = 3;
//    //tp->next = new ListNode;
//    //tp = tp->next;
//    //tp->val = 4;
//    test.swapPairs(h);
//
//    system("pause");
//    return 0;
//}