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
        for(auto cur = dummy->next; cur; cur = cur->next) len++;
        // if(len == 0) return nullptr;
        // if(len == 1) return dummy->next;
        int step = k % len;
        if(step == 0) return dummy->next;
        int step2 = len - step;
        
        auto cur = dummy;
        while(step2--) cur = cur->next;
        auto nxt1 = cur->next;
        auto first = dummy->next;
        cur->next = nullptr;
        dummy->next = nxt1;
        
        cur = nxt1;
        while(cur->next) cur = cur->next;
        cur->next = first;

        return dummy->next;
    }
};