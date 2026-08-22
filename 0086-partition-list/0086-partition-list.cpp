/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
       auto d1 = new ListNode(0, 0), d2 = new ListNode(0, 0);
       auto t1 = d1, t2 = d2;
       for(auto cur = head; cur; cur = cur->next) {
            if(cur->val < x) {
                t1->next = cur;
                t1 = t1->next;
            } else {
                t2->next = cur;
                t2 = t2->next;
            }
       } 
       t1->next = d2->next;
       t2->next = nullptr;
       return d1->next;
    }
};