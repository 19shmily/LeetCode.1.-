#include<iostream>

using namespace std;

//合并两个有序链表
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution_21 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) { return list2; }
        if (!list2) { return list1; }
        int n = 0, m = 0;
        ListNode* ret = NULL;
        ListNode* rear = NULL;
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        while (1)
        {
            if (!p1)
            {
                rear->next = p2;
                return ret;
            }
            if (!p2)
            {
                rear->next = p1;
                return ret;
            }
            if (p1->val > p2->val)
            {

                if (!ret)
                {
                    ret = p2;
                    rear = ret;
                    p2 = p2->next;
                }
                else
                {
                    rear->next = p2;
                    rear = p2;
                    p2 = p2->next;
                }
            }
            else
            {
                if (!ret)
                {
                    ret = p1;
                    rear = ret;
                    p1 = p1->next;
                }
                else
                {
                    rear->next = p1;
                    rear = p1;
                    p1 = p1->next;
                }
            }
        }
    }
};

//合并两个有序链表的main函数
//int main()
//{
//    ListNode* back = NULL;
//    ListNode* tmp = NULL;
//    ListNode* l1 = NULL;
//    ListNode* l2 = NULL;
//    l1 = new ListNode(1);
//    back = l1;
//    tmp = new ListNode(2);
//    back->next = tmp;
//    back = tmp;
//    tmp = new ListNode(4);
//    back->next = tmp;
//    back = tmp;
//    l2 = new ListNode(1);
//    back = l2;
//    tmp = new ListNode(3);
//    back->next = tmp;
//    back = tmp;
//    tmp = new ListNode(4);
//    back->next = tmp;
//    back = tmp;
//    Solution_21 test;
//    ListNode* ret = test.mergeTwoLists(l1, l2);
//
//
//    system("pause");
//    return 0;
//}