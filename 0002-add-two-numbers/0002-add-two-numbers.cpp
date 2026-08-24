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
        auto dummy = new ListNode(0, 0);
        auto cur = dummy;
        int carry = 0;

        while(l1 || l2 || carry) {
            int sum = carry;
            if(l1) {sum += l1->val; l1 = l1->next;}
            if(l2) {sum += l2->val; l2 = l2->next;}

            carry = sum / 10;
            cur->next = new ListNode(sum % 10, 0);
            cur = cur->next;
        }
        
        return dummy->next;
    }
};