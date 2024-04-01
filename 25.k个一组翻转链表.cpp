#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    int count;
    ListNode* tmp_head;
    ListNode* tmp_rear;
    ListNode* sec;
    ListNode* work(ListNode* index,int k)
    {
        if (!index) { return NULL; }
        count++;
        if (k == count)
        {
            sec = index->next;
            tmp_head = index;
            return index;
        }
        else
        {
            ListNode* ret = work(index->next, k);
            if (ret == NULL) { return NULL; }
            ret->next = index;
        }
        return index;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        count = 0;
        ListNode* index = head;
        while (index)
        {
            ListNode* ret = work(index, k);
            if (ret == NULL) 
            {
                tmp_rear->next = index;
                return head;
            }
            ret->next = NULL;
            if (head == index)
            {
                head = tmp_head;
            }
            else
            {
                tmp_rear->next = tmp_head;
            }
            tmp_rear = ret;
            index = sec;
            count = 0;
        }
        return head;
    }
};