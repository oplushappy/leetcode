class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char tmp;
        for(auto &ch : s) {
            if(ch == ')') {
                if(st.empty()) return false;
                tmp = st.top();
                if(tmp != '(') return false;
                st.pop();
            } else if(ch == ']') {
                if(st.empty()) return false;
                tmp = st.top();
                if(tmp != '[') return false;
                st.pop();
            } else if(ch == '}') {
                if(st.empty()) return false;
                tmp = st.top();
                if(tmp != '{') return false;
                st.pop();
            } else {
                st.push(ch);
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};