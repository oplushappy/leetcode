class MyQueue {
    stack<int> st1;
    stack<int> st2;
    int size = 0;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        size++;
        st1.push(x);
        auto tmp = st1;
        stack<int> empty;
        swap(empty, st2);
        while(!tmp.empty() && st2.size() != size) {
            st2.push(tmp.top());
            tmp.pop();
        }
    }
    
    int pop() {
        size--;
        int ans = st2.top();
        st2.pop();
        return ans;
    }
    
    int peek() {
        int ans = st2.top();
        return ans;
    }
    
    bool empty() {
        return st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */