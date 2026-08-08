/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        queue<Node*> q;
        Node * dummy = new Node(node->val, node->neighbors);
        q.push(dummy);
        unordered_map<Node*, Node*> m;
        m.insert({node, dummy});

        while(!q.empty()) {
            auto n = q.front();
            q.pop();
            for(Node* & adj : n->neighbors) {
                auto it = m.find(adj);
                if(it == m.end()) {
                    Node * tmp = new Node(adj->val, adj->neighbors);
                    m.insert({adj, tmp});
                    q.push(tmp);
                    adj = tmp;
                } else {
                    adj = it->second;
                }
            }
        }
        return dummy;
    }
};