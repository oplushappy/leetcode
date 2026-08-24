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
    ListNode* oddEvenList(ListNode* head) {
        auto d1 = new ListNode(0, 0);
        auto d2 = new ListNode(0, 0);
        auto t1 = d1, t2 = d2;

        int i = 1;
        auto cur = head;
        while(cur) {
            if(i % 2 == 1) {
                t1->next = cur;
                t1 = cur;
            } else {
                t2->next = cur;
                t2 = cur;
            }
            i++;
            cur = cur->next;
        } 
        t1->next = d2->next;
        t2->next = nullptr;
        return d1->next;
    }
};