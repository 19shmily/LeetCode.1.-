#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#include<string.h>
#include <stdbool.h>

//两数相加

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int a = 0;
    int b = 0;
    int sum = 0;
    int carry = 0;
    struct ListNode* p = NULL;
    struct ListNode* p1 = NULL;
    struct ListNode* p2 = NULL;
    while (l1 || l2)
    {
        if (l2 == NULL)
        {
            a = l1->val;
            b = 0;
        }
        else if (l1 == NULL)
        {
            a = 0;
            b = l2->val;
        }
        else
        {
            a = l1->val;
            b = l2->val;
        }
        if (carry == 1)
        {
            sum = a + b + carry;
            carry = 0;
        }
        else
        {
            sum = a + b;
        }
        if (sum > 9)
        {
            sum = sum % 10;
            carry = 1;
        }
        p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (p == NULL)
        {
            p = p1;
            p1->val = sum;
            p1->next = NULL;
            p2 = p1;
            if (l2 == NULL)
            {
                l1 = l1->next;
            }
            else if (l1 == NULL)
            {
                l2 = l2->next;
            }
            else
            {
                l1 = l1->next;
                l2 = l2->next;
            }
            continue;
        }
        p1->val = sum;
        p1->next = NULL;
        p2->next = p1;
        p2 = p1;
        if (l2 == NULL)
        {
            l1 = l1->next;
        }
        else if (l1 == NULL)
        {
            l2 = l2->next;
        }
        else
        {
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    if (carry == 1)
    {
        p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        p1->val = 1;
        p1->next = NULL;
        p2->next = p1;
        p2 = p1;
    }
    return p;
}