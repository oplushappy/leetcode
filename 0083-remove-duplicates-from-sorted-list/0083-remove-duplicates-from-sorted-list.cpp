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
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(0, head);
        unordered_set<int> s;
        auto prev = dummy;
        for(auto cur = dummy->next; cur; cur = cur->next) {
            int curV = cur->val;
            if(s.count(curV)) {
                prev->next = cur->next;
                continue;
            } 
            s.insert(curV);
            prev = cur;
        }
        return dummy->next;
    }
};