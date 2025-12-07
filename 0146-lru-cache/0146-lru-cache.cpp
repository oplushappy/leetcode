class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> cache;
    Node * left;
    Node * right;

    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    void remove(Node * node) {
        Node * prev = node->prev;
        Node * nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    void insert(Node * node) {
        Node * prev = right->prev;
        node->next = right;
        node->prev = prev;
        prev->next = node;
        right->prev = node;
    }

    int get(int key) {
        if(cache.count(key)) {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            remove(cache[key]);
        }
        Node* new_node = new Node(key, value);
        cache[key] = new_node;
        insert(new_node);

        if(cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            // this step notice
            cache.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */