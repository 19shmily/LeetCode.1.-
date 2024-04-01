#include<iostream>
#include<vector>
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
    multimap<int, ListNode*>mp;
    ListNode* ret;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto it = lists.begin(); it != lists.end(); it++)
        {
            auto move = (*it);
            while (move)
            {
                mp.insert({ move->val,move });
                move = move->next;
            }
        }
        ret = NULL;
        ListNode* move = NULL;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (!ret)
            {
                ret = (*it).second;
            }
            else
            {
                move->next = (*it).second;
            }
            move = (*it).second;
            move->next = NULL;
        }
        return ret;
    }
};