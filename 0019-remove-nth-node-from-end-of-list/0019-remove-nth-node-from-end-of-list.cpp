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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = head;
        ListNode* cur = head;
        int total = 0;
        while(cur) {
            total++;
            cur = cur->next;
        } 

        int target = total - n;
        ListNode* prev = nullptr;
        cur = head;
        for(int i = 0; i <= target; i++) {
            if(i == target && i == 0) {
                return cur->next;
            }else if(i == target) {
                prev->next = cur->next;
            }
            prev = cur;
            cur = cur->next;
        }
        
        return dummy;
    }
};