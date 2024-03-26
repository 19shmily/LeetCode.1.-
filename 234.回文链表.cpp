#include<iostream>
#include<stack>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//超出时间，*_*
class Solution_234_1 {
    stack<int>stk;
public:
    bool isPalindrome(ListNode* head) {
        if (head->next == NULL) { return true; }
        while (head)
        {
            if (!stk.empty())
            {
                ListNode* p = NULL;
                stack<int>tmp(stk);
                if (head->val == stk.top())
                {
                    p = head;
                    while (p)
                    {
                        if (tmp.top() == p->val)
                        {
                            tmp.pop();
                            p = p->next;
                        }
                        else
                        {
                            break;
                        }
                        if (tmp.empty())
                        {
                            if (!p) { return true; }
                            else { break; }
                        }
                    }
                }
                if (head->next && head->next->val == stk.top())
                {
                    stack<int>tmp(stk);
                    p = head->next;
                    while (p)
                    {
                        if (tmp.top() == p->val)
                        {
                            tmp.pop();
                            p = p->next;
                        }
                        else
                        {
                            break;
                        }
                        if (tmp.empty())
                        {
                            if (!p) { return true; }
                            else { break; }
                        }
                    }
                }
            }
            stk.push(head->val);
            head = head->next;
        }
        return false;
    }
};

//看了题解自己写的迭代
class Solution_234_2 {
    ListNode* h;
    bool work(ListNode* p)
    {
        if (p)
        {
            if (work(p->next))
            {
                if (h->val == p->val)
                {
                    h = h->next;
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
public:
    bool isPalindrome(ListNode* head) {
        h = head;
        return work(head);
    }
};