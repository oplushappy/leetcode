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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int car = 0;
        auto dummy = new ListNode(0, 0);
        auto t1 = dummy;
        while(l1 && l2) {
            int tmp = l1->val + l2->val;
            if(car) tmp += 1;
            if(tmp >= 10) {
                t1->next = new ListNode(tmp - 10, 0);
                car = 1;
            } else {
                t1->next = new ListNode(tmp, 0);
                car = 0;
            }
            t1 = t1->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int tmp = l1->val;
            if(car) tmp += 1;
            if(tmp >= 10) {
                t1->next = new ListNode(tmp - 10, 0);
                car = 1;
            } else {
                t1->next = new ListNode(tmp, 0);
                car = 0;
            }
            t1 = t1->next;
            l1 = l1->next;
        }
        while(l2) {
            int tmp = l2->val;
            if(car) tmp += 1;
            if(tmp >= 10) {
                t1->next = new ListNode(tmp - 10, 0);
                car = 1;
            } else {
                t1->next = new ListNode(tmp, 0);
                car = 0;
            }
            t1 = t1->next;
            l2 = l2->next;
        }
        if(car) t1->next = new ListNode(1, 0);
        return dummy->next;
    }
};