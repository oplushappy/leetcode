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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        for(auto cur = head; cur; cur = cur->next) v.push_back(cur);
        int begin = 0;
        int end = v.size() - 1;        
        auto cur = head;
        int i = 1;
        while(begin < end) {
            if(i % 2 == 1) {
                cur->next = v[end];
                begin++;
                cur = cur->next;
            } else {
                cur->next = v[begin];
                end--;
                cur = cur->next;
            }
            i++;
        }
        cur->next = nullptr;
    }
};