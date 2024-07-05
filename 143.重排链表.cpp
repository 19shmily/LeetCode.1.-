#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution_143 {
    vector<ListNode*>rem;
public:
    void reorderList(ListNode* head) {
        ListNode* move = head;
        while (move)
        {
            rem.push_back(move);
            move = move->next;
        }
        int l = 0, r = rem.size() - 1;
        bool flag = true;
        while(l<r)
        {
            if (flag)
            {
                rem[l]->next = rem[r];
                rem[r]->next = NULL;
                l++;
            }
            else
            {
                rem[r]->next = rem[l];
                rem[l]->next = NULL;
                r--;
            }
            flag = !flag;
        }
        return;
    }
};