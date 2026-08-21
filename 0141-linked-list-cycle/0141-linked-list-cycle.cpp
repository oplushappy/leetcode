/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> s;
        for(ListNode *cur = head; cur != nullptr; cur = cur->next) {
            if(s.count(cur)) return true;
            s.insert(cur);
        }
        return false;
    }
};