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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        ListNode* dummy = new ListNode(0, head);
        int len = 0;
        auto T = dummy;
        for(; T->next; T = T->next) len++;
        int step = k % len;
        if(step == 0) return dummy->next;
        int step2 = len - step;
        
        auto K = dummy;
        while(step2--) K = K->next;
        auto N = K->next;
        auto F = dummy->next;
        K->next = nullptr;
        dummy->next = N;
        T->next = F;

        return dummy->next;
    }
};