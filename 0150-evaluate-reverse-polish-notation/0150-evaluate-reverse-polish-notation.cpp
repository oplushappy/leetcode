class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(const string& token : tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int tmp2 = st.top(); st.pop();
                int tmp1 = st.top(); st.pop();
                if(token == "+") {
                    st.push(tmp1 + tmp2);
                } else if(token == "-") {
                    st.push(tmp1 - tmp2);
                } else if(token == "*") {
                    st.push(tmp1 * tmp2);
                } else if(token == "/") {
                    st.push(tmp1 / tmp2);
                }
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};