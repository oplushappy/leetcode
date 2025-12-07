/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> old_to_copy;
        old_to_copy[nullptr] = nullptr;

        Node * cur = head;
        while(cur) {
            old_to_copy[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while(cur) {
            Node * copy = old_to_copy[cur];
            copy->next = old_to_copy[cur->next];
            copy->random = old_to_copy[cur->random];
            cur = cur->next;
        }

        return old_to_copy[head];
    }
};